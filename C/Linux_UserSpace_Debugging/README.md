# <ins>Linux User Space Debugging</ins>
### What is GDB? 
* GDB stands for GNU debugger, is a tool designed to assist in debugging binary object files generated during the compilation process
* GDB enables you to observe the behavior of your program, offering substantial assistance when the program crashes, particularly in cases of segmentation faults.

### Uses of GDB
* Execute a program line by line.
* Establish a breakpoint to halt your program.
* Configure your program to pause under specific conditions.
* Display the current values of variables.
* Inspect the contents of any frame within the call stack.
    
### Languages Supported by GDB
* Ada, Assembly, C, C++, D, Fortran, GO, Objective-C, OpenCL, Modula-2, Pascal, Rust

### Install GDB
```bash
sudo apt-get install gdb
```
Find the version of GDB
```bash
gdb --version
```

### How to compile a program to use with gdb?
```bash
gcc main.c -g -o main.out
or
gcc main.c -o main.out -g
or 
gcc main.c -g --> as a.out is automatically created instead of main.out
```

**-g** tells the compiler to store the symbol table information in the executable. It includes
* Symbol names
* Type information for symbols
* Files and line numbers where the symbols came from

Note : Check the size of binary file with and without the debugging symbols.

```
gcc main.c -o main.out
gcc main.c -o main_debug.out -g
size main.out
size main_debug.out

or 
ls -la  --> this will list all the files with size so we can see the filesize without using the size everytime.

```
### How to run a gdb?
Either type **gdb** with the binary file name or enter into gdb by simply typing the **gdb** and use **file** command with path to the binary file

Method -1
```
gdb ./main.out
< Also it will show all other details too which I removed here >
Reading symbols from ./main_g.out...
quit
```

Method -2
```
gdb
file ./main_debug.out
< Also it will show all other details too which I removed here >
Reading symbols from ./main_g.out...
quit
```
**list** - to see the contents of source file in the gdb
    
    * list 1 => to list the contents of a source file from line 1.
    * list 4, 8 => to list the contents of a source file from line 4 to 8.
    * list 10 => to list the line number 10 code.
    * list <function name> => to print the specific function in source code.

**run or r** - to run the source code in the gdb  ==> shortcut is **r** instead of run

**quit or q** - to quit the gdb session ==> shortcut is **q** instead of quit

**--quiet or -q** - to skip the lot of gbd realted environment informations while running gdb
```
gdb --quiet ./main.out
```

### Breakpoints
The whole purpose of coming to gdb was to pause, observe and proceed.There is no point in running a program without a breakpoint!.
Breakpoints can be used to stop the program at a designated point. Whenever gdb gets to a breakpoint it halts execution of your program and allows you to examine it. Simplest way of putting a breakpoint is using the function name or a line number.
```
(gdb) break normal_Function 
Breakpoint 1 at 0x1222: file main.c, line 21.

(gdb) break 11
Breakpoint 2 at 0x11d9: file main.c, line 12.
```
we can use **b** instead of **breakpoint**

**List of available functions**

This shows a list of available functions in the source code including the library functions
```
(gdb) info functions
```
**List of available breakpoints**

This shows a list of available breakpoints in the current gbd and also shows the information how many times the breakpoint hit.
```
(gdb) info breakpoints
```
**next**
 
 Once the breakpoint hit, we can use the next command to move to the next line of the source code. Also next is used to come out of the function.

 **continue**
 To move from one breakpoint to next breakpoint or continue a program after breakpoint then we can use this continue command. Instead of going line by line we can go from one breakpoint and stop in the next breakpoint.

**delete**
 Use a delete command with breakpoint number to delete that breakpoint
 ```
 delete 2
 ```
 this above command will delete the breakpoint 2.

 **step**
 This command is used to step into the function. Where sometimes the library functions like printf will be executed step by step using step command. In that case use **finish** command to come out of the fucntion.

 **enter**
 To execute the previously typed command simply give enter then it will automatically execute the previous command.

### Command Line Arguments
**Different ways to pass command line arguments to gdb**

You can run gdb with --args parameter.

Method 1
```
gdb --args main.out arg1 arg2 arg3
```
Method 2
```
gdb ./a.out
(gdb) r arg1 arg2 arg3
```
### Backtrace 
A backtrace provides a summary of the call stack, showing how the program reached its current point of execution. It displays the sequence of function calls, from the currently executing function (frame zero) up to the function that initiated the program (e.g., main). 
```
Syntax : backtrace or bt
``` 
```
(gdb) bt
#0  my_function (arg1=10, arg2=20) at my_source.c:50
#1  0x0000555555554789 in another_function (param=5) at another_source.c:120
#2  0x0000555555554654 in main () at main.c:15
```
This backtrace indicates that my_function is currently executing (frame #0), which was called by another_function (frame #1), which in turn was called by main (frame #2).
We can use a frame command to move into the specific frame. 
```
Syntax : frame <Number of the frame>
```
To print any variable value of source code in gdb, we need to use the print command
```
Syntax : print <variable name>
```
```
(gdb) bt
#0  0x00007ffff7c86f90 in __GI__IO_getline_info (fp=fp@entry=0x7ffff7e038e0 <_IO_2_1_stdin_>, buf=buf@entry=0x0, n=n@entry=1023, delim=delim@entry=10, 
    extract_delim=extract_delim@entry=1, eof=eof@entry=0x0) at ./libio/iogetline.c:77
#1  0x00007ffff7c8707c in __GI__IO_getline (fp=fp@entry=0x7ffff7e038e0 <_IO_2_1_stdin_>, buf=buf@entry=0x0, n=n@entry=1023, delim=delim@entry=10,
    extract_delim=extract_delim@entry=1) at ./libio/iogetline.c:34
#2  0x00007ffff7c85bd4 in _IO_fgets (buf=0x0, n=1024, fp=0x7ffff7e038e0 <_IO_2_1_stdin_>) at ./libio/iofgets.c:53
#3  0x00005555555551c4 in main (argc=1, argv=0x7fffffffc8c8) at main.c:7
(gdb) frame 3
#3  0x00005555555551c4 in main (argc=1, argv=0x7fffffffc8c8) at main.c:7
7           fgets(buf,1024,stdin);
(gdb) list
2       #include<stdio.h>
3
4       int main(int argc, char*argv[]){
5           char* buf;
6           buf = (char*)malloc(1<<31);
7           fgets(buf,1024,stdin);
8           printf("%s\n",buf);
9           return 1;
10      }
(gdb) print buf
$1 = 0x0
(gdb)
```
As we can see clearly from above code that malloc creates a segmentation fault. Better way would be checks the return valus of malloc and proceed further. But that is not the case in our code.

### Displaying Data
You can use print command to display the value of variables and other expressions. The print or p command takes any C expression as its argument:

p [/format][expression]

Use **help p** or **help print** for details 

**Note:** Before print make sure you have applied breakpoint in that varible that you are trying to print
```
(gdb) print i
(gdb) print &i  => address of i
(gdb) print sizeof(i)
(gdb) print sizeof(&i)
(gdb) print /x i => print i value in hexadecimal
(gdb) print /o i => print i value in octal
(gdb) print /t i => print i value in binary
```
gdb comes with a powerful tool for directly examining memory: the x command. The x command examine memory, starting at a particular address.
```
(gdb) x &i => print the address of i
0x7ffffffdedc: 0x00000539
```
It comes with a number of formatting commands that provide precise control over how many bytes you'd like to examine and how you'd like to print them
```
(gdb) x/4xb &i => print i value in 4 bytes with hexadecimal format
0x7ffffffdedc: 0x39 0x05 0x00 0x00
```
The flags indicate that I want to examine 4 values formatted as hex numerals, one byte at a time. On Intel machines, bytes are stored in "little-endian" order
```
(gdb) p msg
$2 = "Hello World"
(gdb) x msg
0x7ffffffdec0: ox6c6c6548
(gdb) x/s msg   => to print a msg variable in string format
0x7ffffffdec0: "Hello World"
```

### Datatype
ptype command is used to get the data type of a variable or signature of a function.
```
(gdb) ptype val
type = int
(gdb) ptype &val
type = int *
(gdb) ptype main
type = int (int, char ***)
```

### Modify Variable Value
We can modify the value of a variable in th source code in gdb, using set command
```
Syntax : set <variable name> = <value for variable>
```
```
(gdb) b main
Breakpoint 1 at 0x115c: file string.c, line 3.
(gdb) r
< Information related to gbd and its environments are removed here for ease of use>

Breakpoint 1, main (argc=1, argv=0x7fffffffc8a8) at string.c:3
3       int main(int argc, char*argv[]){
(gdb) next
4           char msg[] = "Hello World";
(gdb) x/s msg
0x7fffffffc76c: "\377\177"  ==> we can see some garbage because we havent executed the line 4 of code yet
(gdb) next              ==> by next command we move into the next line
5           return 0;
(gdb) x/s msg           ==> examine the variable msg in string 
0x7fffffffc76c: "Hello World"
(gdb) set msg="Linux"   ==> we can modify the variable in gdb
(gdb) x/s msg
0x7fffffffc76c: "Linux"
```


