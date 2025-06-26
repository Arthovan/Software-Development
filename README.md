# GCC compilation and useful commands for coding
[README](https://medium.com/analytics-vidhya/how-to-create-a-readme-md-file-8fb2e8ce24e3)


For C++ we have to use *g++*, for C use *gcc*

## Preprocessing -E
```bash
g++ -E main.cpp -o main.i   
```
(or)
```bash	
g++ main.cpp -o main.i -E
```
-E for Preprocessing, -o output file option

## Compiling -S
```bash
g++ -S main.i -o main.s   
```
(or)
```bash          	
g++ main.i -o main.s -S
```

## Assembling -c
```bash
g++ -c main.s -o main.o   
```
(or)
```bash  	
g++ main.s -o main.o -c
```

## Linking
```bash
g++ main.o -o main.out
```
## Other Methods
```bash
g++ -c main.cpp -o main.o	
```
(or)
```bash
g++ main.cpp -c
```
To create an object file from source file
```bash
g++  main.o -o main.out	
```
To create an executable from object file
```bash
g++ main.cpp
```
To create a executable directly from source file and default executable name is a.out
## Compiler Optimisation
```bash
g++ main.cpp -o compiler_opt_0 -O0  	
```
compiler optimization flag at the end as O0
```bash
g++ main.cpp -o compiler_opt_1 -O1	
```
compiler optimization flag at the end as O1

## Useful Commands
### Time
```bash
Time ./compiler_opt_0	
```
Time is a command in a linux to run the program and show the resources used by it

### Objdump
```bash
Objdump -D main.out	
```
Objdump is a linux command to analyze the object file, use *objdumb --help* to see list of available options. **-D** will disassemble all sections of object code

### ldd
```bash
ldd main.out
```
ldd prints the shared object dependencies

### nm
```bash
nm -D libstdc++.so.6 => /lib/x86_64-linux-gnu/libstdc++.so
```
nm will List a symbols from object files, **-D** means dynamic
```bash
nm main.o
```
Displays symbols in the **main.o** file
### ld
**ld** is a GNU linker

### clang-format
```bash
clang-format <filename>	
```
To align the format of the code. We can install the clang using 
```bash 
sudo apt-get install clang-format
```
We can align the code in different style using the **--style** option
```bash
clang-format <filename> --style=file
```
## Coding
### Inline
```bash
Inline <data type> <variable name>
```
Some time we may compile the file separately and link them together for compilation. The global variable can cause linking error as global variable name is used in different places as symbol is found twice in the object file. In order to avoid this either we can use a extern keyword or inline before the global variable definition.
#### Example 1 : 
```bash
inline int data =10;
```
#### Static and Dynamic Linking
```bash
g++ main.cpp -o main_dynamic.out
```
By default if we use the above command, then **STL library** or any other header files we used are linked dynamically.
```bash           
g++ main.cpp -o main_static.out -static-libstdc++
```
If we need static linking then we need to specify the commands like above, also static will have the library in the executable file instead of dynamic linking.
```bash
ldd main_static.out
```
Using ldd we can inspect library dependencies of files and we can clearly see the statically linked library has executable part inside the code rather than linking dynamically
```bash
objdump -dC main_dynamic >main_dynamic.s
```
Creating a disassembly of dynamic executable file
```bash
objdump -dC main_static >main_static.s
```
Creating a disassembly of static executable file
```bash
vim -o main_static.s main_dynamic.s
```   
We can view both the disassembled files in the split window of vim
Note: Use ctrl+w to move between the split windows

#### Static Libraries
**add.cpp**
```
int add(int a, int b){
return a + b;
}
```
**add.h**
```
#pragma once    //    This is used instead of header guards
int add(int, int);
```
**multiply.cpp**
```
int multiply(int a, int b){
return a * b;
}
```
**multiply.h**
```
#pragma once    //    This is used instead of header guards
int multiply(int , int );
```
**main.cpp**
```
#include <iostream>
#include "add.h"
#include "multiply.h"

int main(){
    auto sum = add(10, 20);
    std::cout << "Sum: " << sum << '\n';
    
    auto product = multiply(10, 20);
    std::cout << "Product: " << product << '\n';
    return 0;
}
```
**ar** is a command to create, modify, and extract from archives.
```
ar
```
To see the list of options available in ar use the below commands
```
ar --help
```
Create an object files for add and multiply
```
g++ add.cpp -c
g++ multiply.cpp -c
```
Create an archive with an options crs, where Library name is libtest.a and input for library is multiply.o and add.o.
Use ar --help to see the list of available options.
```
ar -crs libtest.a multiply.o add.o
```
To see the contents of the achieve libtest.a
```
ar -t libtest.a
```
While compiling a main.cpp we need to specify the linking option -l 

**Note:** By default library files search for **lib** as starting name and **.a** as ending name, we need to specify the remaining name after **-l**. In our case **libtest.a** is a file and we need to specify **-ltest**. So the compiler will interpret the **-ltest** as **libtest.a**
```    
g++ main.cpp -o a.out -ltest
```
This command will trigger an error as the compiler cannot find **-ltest**. Because we didn’t specify the path where the **libtest.a** is located in our system.
```
g++ main.cpp -o a.out -ltest -L./
```
Where **-L** is for path option and **./** is a current directory.
