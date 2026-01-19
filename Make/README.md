# Makefile for C/C++ Projects
A **Makefile** is used by the `make` build tool to automate tasks — typically compiling programs.
Always name the file **Makefile** (capital **M**). 

**Example:** `Makefile`

A Makefile is made up of **rules**, where each rule has:

*   **target** → the output you want to build (example: `main`, `main.o`)

*   **dependencies** → files the target depends on

*   **command** → the shell command used to build the target (must begin with a tab)

```Makefile
target: dependencies
<TAB> command
```
## Basic Structure: 
### `main.cc`

```c++
#include <iostream>

using namespace std;

int main(int argc, char*argv[]){
    cout<<"Hello World!"<<endl;
    return 0;
}
```
### `Makefile`
```Makefile
build:
	g++ main.cc -o main

execute:
	./main
```
💡**Tip :**  use `g++` for C++ and `gcc` for C files.

### Explanation:

*   The `build` target compiles `main.cc` directly into an executable named `main`.

*   The `execute` target runs the compiled program.

## Clean Target: 
(Same `main.cc` as Example 1)

### `Makefile`
```Makefile
build:
	g++ main.cc -c main.o
	g++ main.o -o main

execute:
	./main

clean:
    rm -f *.o
	rm -f main
```

### Explanation:

*   The `build` target first compiles the source file into an object file (`main.o`), then links it into an executable (`main`).

*   The `clean` target removes all generated object files and the executable.

## Multiple Source Files: 
### `main.cc`

```c++
#include <iostream>
#include "print.h"

using namespace std;

int main(int argc, char*argv[]){
    printText();
    return 0;
}
```

### `print.cc`

```c++
#include <iostream>

void printText() {
    std::cout<< "Hello World!" <<std::endl;
}
```

### `print.h`

```c++
#pragma once

void printText();
```
### `Makefile`
```Makefile
build:
	g++ main.cc -c main.o
	g++ print.cc -c print.o
	g++ main.o print.o -o main

execute:
	./main

clean:
	rm -f *.o	# remove all the .o files
	rm -f main	# remove the main executable
```

### Explanation:
This Makefile compiles both `main.cc` and `print.cc` into object files, and then links them to create the final executable.
In larger projects, object files are usually compiled separately and linked later—this is closer to real project structure.

## Separate Target for object and source: 
(Same source files as Example 3)

## Makefile
```Makefile
build: main.o print.o
	g++ main.o print.o -o main

main.o:
    g++ main.cc -c main.o

print.o:
	g++ print.cc -c # another valid way to generate print.o without explicitly naming it

execute:
	./main

clean:
	rm -f *.o	# remove all the .o files
	rm -f main	# remove the main executable
```

### Explanation:

*   The `build` target depends on `main.o` and `print.o`.
*   Each object file is generated in its own rule.
*   `print.o` demonstrates that you can omit the output filename; the compiler infers it automatically.

## Variables
We can create a variables in Makefile but the value of the variable is always considered as strings, where single or double quotes for variable names or values have no meaning.

For convention we use capital lettes for varible name with undescore as separator for large names. We can use format but mostly we will stick with the conventional method.

**Example:** DEBUG_FLAG = 1

Where 1 is considered as string in Makefile and we dont have to include that in single or double quotes.

## Compiler Flags
There are certain predefined varibles in the Makefile which has some meaning for it. Those variables are
*   CC  -   Program for compiling C programs; default cc
*   CXX -   Porgram for compiling C++ programs; default g++
*   CFLAGS  -   Extra flags to give to the C compiler
*   CXXFLAGS    -   Extra flags to give to the C++ compiler
*   CPPFLAGS    -   Extra flags to give to the C preprocessor
*   LDFLAGS    -   Extra flags to give to the linker

Inorder to see the list of predefined variables and its values in Makefiles. Use the `make - p` command in the terminal.

We can define this variables in the top of the Makefile with their respective values

**Example:**
```Makefile
CXX = g++
CXXFLAGS = -Wall -Wextra -Wpedantic -std=c++17
LDFLAGS = -lmath
```

### -Wall – Enable Most Warnings

Warn all (common warnings)

This turns on a large set of useful warnings, such as:
*   unused variables
*   type conversion issues
*   missing return statements
*   uninitialized variables

### -Wextra – Extra Warnings

Turns on more warnings that -Wall does not include, such as:
*   unused parameters
*   signed/unsigned comparison
*   suspicious code patterns
*   Developers normally use both -Wall and -Wextra.

### -Wpedantic – Strict ISO C++ Compliance

This flag forces the compiler to strictly follow the C++ standard and warn about:
*   compiler extensions
*   non-standard language constructs
*   non-portable code

This helps you write portable, standard-compliant code.

### -std=c++17 – Use C++17 Standard

This tells the compiler to use the C++17 language standard.

It enables features like:
*   std::optional
*   std::variant
*   std::filesystem
*   structured bindings
*   if with initializer

...and many more C++17 features.

### -lmath
* -l<name> tells the linker to link with a library named lib<name>.so or lib<name>.a.
* So, -lmath means link with libmath.

**Important:**

* On most systems, the standard math library is called libm, not libmath.

* If you actually want math functions like sin(), cos(), sqrt(), you should use:

```Makefile
LDFLAGS = -lm
```

* -lm links the math library that provides functions from <cmath> or <math.h>.

Inorder to use the above mentioned flags we can add them in a single variable like below

```Makefile
CXX_COMPILER_CALL = $(CXX) $(CXXFLAGS)
```
Now the updated `Makefile` will look like this :

```Makefile
# our own variable
CXX_STANDARD = c++17
CXX_WARNINGS = -Wall -Wextra -Wpedantic

# default variable in Make
CXX = g++
CXXFLAGS =  $(CXX_WARNINGS) -std=$(CXX_STANDARD)
# LDFLAGS = -lmath	# as this wont work now in windows machine we can comment it and use empty LDFLAGS below
LDFLAGS = 

# our own variable
CXX_COMPILER_CALL = $(CXX) $(CXXFLAGS)

# we can use any name we want but for undestanding am using build here
build: main.o print.o
	$(CXX_COMPILER_CALL) main.o print.o $(LDFLAGS) -o main

main.o:
    $(CXX_COMPILER_CALL) main.cc -c main.o

print.o:
	$(CXX_COMPILER_CALL) print.cc -c # another valid way to generate print.o without explicitly naming it

execute:
	./main

clean:
	rm -f *.o	# remove all the .o files
	rm -f main	# remove the main executable
```
💡**Tip :**  There may be cases where we have to overwrite a default value which we mentioned in the `Makefile`. During that case specify the variable with value while invoking the `make build`

**Example:** 
```bash
make build CXX_STANDARD=c++14 # instead of using the c++17 our make will use c++14 as standard
```
### Conditional Statement
Generally we provide a sotware for testing or release it for customer. In testing phase we have to compile the software without any optimization and provide debug information whereas incase of release mode we provide software with high optimazation and less debug information. This can be done in the `Makefile` itself.

```Makefile
DEBUG = 1

# += means we are appending into the CXXFLAGS
ifeq($(DEBUG), 1)   # if DEBUG equal to 1
CXXFLAGS += -g -O0  # add debug flag as well as no optimization
else
CXXFLAGS += -O3     # if DEBUG is not equal to 1 then add debug flag with high optimazation
endif
```
After this code our `Makefile` will look like this :

```Makefile
############# our own variable ############
DEBUG = 1
CXX_STANDARD = c++17
CXX_WARNINGS = -Wall -Wextra -Wpedantic
EXECUTABLE_NAME = main
###########################################

##### default variable in Make ############
CXX = g++
CXXFLAGS =  $(CXX_WARNINGS) -std=$(CXX_STANDARD)
# LDFLAGS = -lmath	# as this wont work now in windows machine we can comment it and use empty LDFLAGS below
LDFLAGS = 
###########################################

###########################################
# += means we are appending into the CXXFLAGS
ifeq($(DEBUG), 1)   # if DEBUG equal to 1
CXXFLAGS += -g -O0  # add debug flag as well as no optimization
else
CXXFLAGS += -O3     # if DEBUG is not equal to 1 then add debug flag with high optimazation
endif
###########################################

########### our own variable ##############
CXX_COMPILER_CALL = $(CXX) $(CXXFLAGS)
###########################################

# we can use any name we want but for undestanding am using build here
build: main.o print.o
	$(CXX_COMPILER_CALL) main.o print.o $(LDFLAGS) -o $(EXECUTABLE_NAME)

main.o:
	$(CXX_COMPILER_CALL) main.cc -c main.o

print.o:
	$(CXX_COMPILER_CALL) print.cc -c # another valid way to generate print.o without explicitly naming it

execute:
	./main

clean:
	rm -f *.o	# remove all the .o files
	rm -f main	# remove the main executable
```