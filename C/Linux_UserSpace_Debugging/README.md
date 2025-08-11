# Linux User Space Debugging

## What is GDB?

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
gcc main.c -g       #   as a.out is automatically created instead of main.out
```

**-g** tells the compiler to store the symbol table information in the executable. It includes

* Symbol names
* Type information for symbols
* Files and line numbers where the symbols came from

**Note:** Check the size of binary file with and without the debugging symbols.

```bash
gcc main.c -o main.out
gcc main.c -o main_debug.out -g
size main.out
size main_debug.out
# or
ls -la              #   this will list all the files with size so we can see the filesize without using the size everytime.
```

### How to run a gdb?

Either type **gdb** with the binary file name or enter into gdb by simply typing the **gdb** and use **file** command with path to the binary file

#### Method - 1

```bash
gdb ./main.out
# < Also it will show all other details too which I removed here >
Reading symbols from ./main_g.out...
quit
```

#### Method - 2

```bash
gdb
file ./main_debug.out
# < Also it will show all other details too which I removed here >
Reading symbols from ./main_g.out...
quit
```

**list** - to see the contents of source file in the gdb

* list 1 => to list the contents of a source file from line 1.
* list 4, 8 => to list the contents of a source file from line 4 to 8.
* list 10 => to list the line number 10 code.
* list function name => to print the specific function in source code.

**run or r** - to run the source code in the gdb    ==> shortcut is **r** instead of run

**quit or q** - to quit the gdb session             ==> shortcut is **q** instead of quit

**--quiet or -q** - to skip the lot of gbd realted environment informations while running gdb

```bash
gdb --quiet ./main.out
```

### Breakpoints

The whole purpose of coming to gdb was to pause, observe and proceed.There is no point in running a program without a breakpoint!.
Breakpoints can be used to stop the program at a designated point. Whenever gdb gets to a breakpoint it halts execution of your program and allows you to examine it. Simplest way of putting a breakpoint is using the function name or a line number.

```bash
(gdb) break normal_Function 
Breakpoint 1 at 0x1222: file main.c, line 21.

(gdb) break 11
Breakpoint 2 at 0x11d9: file main.c, line 12.
```

**Note :** If we have multiple source file and we need to apply breakpoint to a particular file then use the below format.

#### Syntax

```bash
break <file_name> : <line number or funcation name>
```

we can use **b** instead of **breakpoint**

#### List of available functions

This shows a list of available functions in the source code including the library functions

```bash
(gdb) info functions
```

#### List of available breakpoints

This shows a list of available breakpoints in the current gbd and also shows the information how many times the breakpoint hit.

```bash
(gdb) info breakpoints
```

#### next

 Once the breakpoint hit, we can use the next command to move to the next line of the source code. Also next is used to come out of the function.

#### continue

 To move from one breakpoint to next breakpoint or continue a program after breakpoint then we can use this continue command. Instead of going line by line we can go from one breakpoint and stop in the next breakpoint.

#### delete

 Use a delete command with breakpoint number to delete that breakpoint

 ```bash
 delete 2
 ```

 this above command will delete the breakpoint 2.

#### step

 This command is used to step into the function. Where sometimes the library functions like printf will be executed step by step using step command. In that case use **finish** command to come out of the fucntion.

#### enter

 To execute the previously typed command simply give enter then it will automatically execute the previous command.

#### where

 To show which line of code currently we are in. Just type "where" command.

### Command Line Arguments

#### Different ways to pass command line arguments to gdb

You can run gdb with --args parameter.

#### Method-1

```bash
gdb --args main.out arg1 arg2 arg3
```

#### Method-2

```bash
gdb ./a.out
(gdb) r arg1 arg2 arg3
```

### Backtrace

A backtrace provides a summary of the call stack, showing how the program reached its current point of execution. It displays the sequence of function calls, from the currently executing function (frame zero) up to the function that initiated the program (e.g., main).

#### Syntax

```bash
backtrace or bt
```

```bash
(gdb) bt
#0  my_function (arg1=10, arg2=20) at my_source.c:50
#1  0x0000555555554789 in another_function (param=5) at another_source.c:120
#2  0x0000555555554654 in main () at main.c:15
```

This backtrace indicates that my_function is currently executing (frame #0), which was called by another_function (frame #1), which in turn was called by main (frame #2).
We can use a frame command to move into the specific frame.

#### Syntax

```bash
 frame <Number of the frame>
```

To print any variable value of source code in gdb, we need to use the print command

#### Syntax

```bash
print <variable name>
```

```bash
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

#### Syntax

```bash
p [/format][expression]
```

Use **help p** or **help print** for details.

**Note:** Before print make sure you have applied breakpoint in that varible that you are trying to print

```bash
(gdb) print i
(gdb) print &i  => address of i
(gdb) print sizeof(i)
(gdb) print sizeof(&i)
(gdb) print /x i => print i value in hexadecimal
(gdb) print /o i => print i value in octal
(gdb) print /t i => print i value in binary
```

gdb comes with a powerful tool for directly examining memory: the x command. The x command examine memory, starting at a particular address.

```bash
(gdb) x &i      #   print the address of i
0x7ffffffdedc: 0x00000539
```

It comes with a number of formatting commands that provide precise control over how many bytes you'd like to examine and how you'd like to print them

```bash
(gdb) x/4xb &i  #   print i value in 4 bytes with hexadecimal format
0x7ffffffdedc: 0x39 0x05 0x00 0x00
```

The flags indicate that I want to examine 4 values formatted as hex numerals, one byte at a time. On Intel machines, bytes are stored in "little-endian" order

```bash
(gdb) p msg
$2 = "Hello World"
(gdb) x msg
0x7ffffffdec0: ox6c6c6548
(gdb) x/s msg   # to print a msg variable in string format
0x7ffffffdec0: "Hello World"
```

### Datatype

ptype command is used to get the data type of a variable or signature of a function.

```bash
(gdb) ptype val
type = int
(gdb) ptype &val
type = int *
(gdb) ptype main
type = int (int, char ***)
```

### Modify Variable Value

We can modify the value of a variable in th source code in gdb, using set command

#### Syntax

```bash
set <variable name> = <value for variable>
```

```bash
(gdb) b main
Breakpoint 1 at 0x115c: file string.c, line 3.
(gdb) r
# < Information related to gbd and its environments are removed here for ease of use>

Breakpoint 1, main (argc=1, argv=0x7fffffffc8a8) at string.c:3
3       int main(int argc, char*argv[]){
(gdb) next
4           char msg[] = "Hello World";
(gdb) x/s msg
0x7fffffffc76c: "\377\177"  #   we can see some garbage because we havent executed the line 4 of code yet
(gdb) next                  #   by next command we move into the next line
5           return 0;
(gdb) x/s msg               #   examine the variable msg in string 
0x7fffffffc76c: "Hello World"
(gdb) set msg="Linux"       #   we can modify the variable in gdb
(gdb) x/s msg
0x7fffffffc76c: "Linux"
```

### Frames

An executing application keeps track of a call stack, which holds details about the functions that have been invoked. Each entry in this stack is known as a call frame, and it includes the necessary information to return to the calling function as well as the data required for the function's local variables.

At the start of your program, the call stack contains just one frame, corresponding to the main function. Whenever a function is called, a new frame is added to the stack, and when a function completes, its frame is removed from the stack. Recursive functions can lead to the creation of numerous frames.

Use backtrace.c for the below commands.

```bash
$ gcc backtrace.c -o backtrace -g
$ gdb ./backtrace
(gdb) b main
(gdb) run
(gdb) bt            #   we can see only main function in stack frame
(gdb) b func1
(gdb) continue
(gdb) bt            #   now we can see func1 and main in stack frame
(gdb) b func2
(gdb) continue
(gdb) bt            #   now we can see main, func1 and func2 in the stack frame
```

#### Moving from one frame to another

You can move between the stack frames using frame command.

#### Syntax

```bash
frame [number]
```

We can debug the code by moving to different frame by using frame command with frame number so that list command will show the codes from that frame.

#### Get information about a stack frame

You can get the information about a particular frame using **'info frame [number]'**.

```bash
(gdb) info frame 1                      #   list information about the current stack frame
(gdb) info variables                    #   list all global and static variables.
(gdb) info locals                       #   list local variable values of current stack frame
(gdb) info registers                    #   list register values
(gdb) info registers <register name>    #   shows just the register mentioned there 
(gdb) info breakpoints                  #   list status of all breakpoints
```

#### Using gdb to view the CPU registers

The shortcut for **'info'** is **'i'** and **'register'** is **'r'**. The **"i r"** command displays the current contents of the CPU registers.

The first column shows the name of the register. Second column shows the content of the register in hexadecimal. Third coulmn shows the contents in 32-bit/64-bit unsigned decimal.

**Note :** If we create a variable in C code with register keyword, then the memeory is allocated for that variable in CPU registers. If we try to print the variable address then it wont be there as it is stored in CPU.

### Conditional Breakpoints

As long as a breakpoint is enabled, the debugger always stops at that breakpoint. However, sometimes it's useful to tell the debugger to stop at a break point only if some condition is met, like when a variable has a particularly interesting value.

You can sepecify a break condition when you set a breakpoint by appending the keyword **"if"** to a normal break statement.

#### Syntax

```bash
break [position] if expression
```

In the above syntax position can be a function name or line number. If you already set a breakpoint at the desired position, you can use the condition command to add or change its break condition:

```bash
condition bp_number [expression]
```

**Example :** For applying conditions together with breakpoint

```bash
gdb ./a.out
# gdb envireonment informations are removed here ease of use
(gdb) list
7
8       #include<stdio.h>
9
10      void myFunction(){
11          // Initialize the counter to 0
12          static int sFunctionCounter = 0;
13
14          // Each time we enter the function, increment the counter
15          sFunctionCounter++;
16      }
(gdb) 
17
18      int main(int argc, const char * argv[]){
19          int i;
20          // call 10 times myFunction.
21          for(i = 0; i < 10; i++){
22              myFunction();
23          }
24          return 0;
25      }
(gdb) b 22 if i==7
Breakpoint 1 at 0x115f: file breakpoint.c, line 22.
(gdb) r
# removed some environment informations
Breakpoint 1, main (argc=1, argv=0x7fffffffc4b8) at breakpoint.c:22
22              myFunction();
(gdb) p i
$1 = 7 # we can see that breakpoint occured when i value reached 7
```

**Example :** For applying conditions for existing breakpoint

```bash
gdb ./a.out
# gdb envireonment informations are removed here ease of use

Reading symbols from ./a.out...
(gdb) list
7
8       #include<stdio.h>
9
10      void myFunction(){
11          // Initialize the counter to 0
12          static int sFunctionCounter = 0;
13
14          // Each time we enter the function, increment the counter
15          sFunctionCounter++;
16      }
(gdb) info breakpoint # we can see that no breakpoints are there
No breakpoints, watchpoints, tracepoints, or catchpoints.
(gdb) list
17
18      int main(int argc, const char * argv[]){
19          int i;
20          // call 10 times myFunction.
21          for(i = 0; i < 10; i++){
22              myFunction();
23          }
24          return 0;
25      }
(gdb) # removed the end of file message
(gdb) b 22
Breakpoint 1 at 0x115f: file breakpoint.c, line 22.
(gdb) r
# removed the running environment details for ease of use

Breakpoint 1, main (argc=1, argv=0x7fffffffc4b8) at breakpoint.c:22
22              myFunction();
(gdb) info breakpoint
Num     Type           Disp Enb Address            What
1       breakpoint     keep y   0x000055555555515f in main at breakpoint.c:22
        breakpoint already hit 1 time
(gdb) condition 1 i==5
(gdb) p i
$1 = 0
(gdb) continue
Continuing.

Breakpoint 1, main (argc=1, argv=0x7fffffffc4b8) at breakpoint.c:22
22              myFunction();
(gdb) p i
$2 = 5  # we can see that the breakpoint is occured when the condition of i value reached to 5
```

### Watchpoints

Watchpoints are similar to breakpoints. Watchpoints are set on variables. When those variables are read or written, the watchpoint is triggered and program execution stops.

#### How do I set a write watchpoint for a variable?

Use the **"watch"** command. The argument to the watch command is an expression that is evaluated. This implies that the variable you want to set a watchpoint on must be in the current scope.

So, to set a watchpoint on a non-global variable, you must have set a breakpoint that will stop your program when the variable is in scope.
You set the watchpoint after the program breaks.

```bash
(gdb) watch x
```

#### How do I set a read watchpoint for a variable?

Use the **"rwatch"** command. Usage is identical to the watch command.

```bash
(gdb) rwatch y 
```

#### How do I set a read/write watchpoint for a variable?

Use the **"awatch"** command. Usage is identical to the watch command.

```bash
(gdb) awatch y 
```

#### How do I enable/disable watchpoints?

Active watchpoints show up the breakpoint list. Use the **"info breakpoint"** command to get this list. Then use the **"disable"** command to turn off a watchpoint, just like disabling a breakpoint. We can use **"enable"** command to enable a breakpoint.

#### Example

```bash
gdb ./a.out
(gdb) b main
Breakpoint 1 at 0x1156: file breakpoint.c, line 21.
(gdb) r             # short form of run
Breakpoint 1, main (argc=1, argv=0x7fffffffc4b8) at breakpoint.c:21
21          for(i = 0; i < 10; i++){
(gdb) watch i       # created a write watch point
Hardware watchpoint 2: i
(gdb) c             # short form of continue
Continuing.
Hardware watchpoint 2: i    # we can see that watch point triggered for 'i' and we can see the values in detail below
Old value = 32767
New value = 0
main (argc=1, argv=0x7fffffffc4b8) at breakpoint.c:21
21          for(i = 0; i < 10; i++){
(gdb) rwatch i      # created a read watch point
Hardware read watchpoint 3: i
(gdb) continue
Continuing.

Hardware read watchpoint 3: i

Value = 0
0x0000555555555171 in main (argc=1, argv=0x7fffffffc4b8) at breakpoint.c:21
21          for(i = 0; i < 10; i++){
(gdb) awatch i      # created a read/write watch point
Hardware access (read/write) watchpoint 4: i
(gdb) continue
Continuing.

Hardware watchpoint 2: i

Old value = 0
New value = 1

Hardware access (read/write) watchpoint 4: i

Old value = 0
New value = 1
0x000055555555516d in main (argc=1, argv=0x7fffffffc4b8) at breakpoint.c:21
21          for(i = 0; i < 10; i++){
(gdb) info b
Num     Type            Disp Enb Address            What
1       breakpoint      keep y   0x0000555555555156 in main at breakpoint.c:21
        breakpoint already hit 1 time
2       hw watchpoint   keep y                      i
        breakpoint already hit 2 times
3       read watchpoint keep y                      i
        breakpoint already hit 1 time
4       acc watchpoint  keep y                      i
        breakpoint already hit 1 time
(gdb) disable 2         # disabled a watchpoint at number 2
(gdb) info b            # see the details of break and watch point
Num     Type            Disp Enb Address            What
1       breakpoint      keep y   0x0000555555555156 in main at breakpoint.c:21
        breakpoint already hit 1 time
2       hw watchpoint   keep n                      i # disabled now
        breakpoint already hit 2 times
3       read watchpoint keep y                      i
        breakpoint already hit 1 time
4       acc watchpoint  keep y                      i
        breakpoint already hit 1 time
(gdb) enable 2          # enable a watch/break point at number 2
(gdb) info b
Num     Type            Disp Enb Address            What
1       breakpoint      keep y   0x0000555555555156 in main at breakpoint.c:21
        breakpoint already hit 1 time
2       hw watchpoint   keep y                      i   # enabled now
        breakpoint already hit 2 times
3       read watchpoint keep y                      i
        breakpoint already hit 1 time
4       acc watchpoint  keep y                      i
        breakpoint already hit 1 time
(gdb) 
```

### gdb Text User Interface (TUI)

The gdb Text User Interface (TUI) is a terminal interface which uses the curses library to show the
        *Source file

* Assembly output
 *Program registers
* GDB Commands
in separate text windows

The TUI mode is supported only on platforms where a suitable version of the curses library is available. The TUI mode is enabled by default when you invoke gdb as either **"gdbtui"** or **"gdb -tui"**.

You can also switch in and out of TUI mode while gdb runs by using various TUI commands and key bindings, such as **Ctrl-x a**

#### Commands

**Ctrl - l** => to repaint the screen //when there are printf's displayed

You can type commands on the command line like usual, but the arrow keys will scroll the source code view instead of paging through history or navigating the entered command.

To switch focus to the command line view, type **ctrl-x o** and the arrow keys works as in the normal command line mode.

Switching back to the source code view is done using the same key combination a second time.

### Logging

You may want to save the output of gdb commands to a file.There are several commands to control gdb’s logging.

```
        set logging on
                Enable logging. 
                GDB saves all output from this point in a text file called gdb.txt that resides in the directory in which
                you are running GDB

        set logging off
         Disable logging.
         Note that you can turn logging on and off several times and GDB will concatenate output to the gdb.txt file

        set logging file file
         Change the name of the current logfile. The default logfile is ‘gdb.txt’.
```

Useful when you’re dealing with a long stack trace, or a multi-threaded stack trace.

**Note :**  Make sure you use **"set logging on"** once you enter into the "gdb". once you are done with the debugging then type the **"set logging off"** so that all the debug commands and information will be stored in the **"gdb.txt"** file.

### Debugging an Already-running Process

#### attach process-id

This command attaches to a running process—one that was started outside gdb.

#### detach

This command attaches to a running process—one that was started outside gdb

```bash
./a.out  #make sure the process is still running while attaching the gdb to it
gdb
(gdb) shell ps -ef | grep a.out # to get process id of running code
#  we will get some PID information here and select the current process PID and attach to it
(gdb) attach <PID> # attach teh gdb to that process
(gdb) detach # after debug we need to detach from that process
```

### Disassembly of the source code

Another Useful function of gdb debugger is the **"disassemble"** command. As its name suggesting, this command helps in disassembling of the provided functions assembler code.
If we want to disassemble **"main"** function. we just need to type

```bash
(gdb) disassemble main
```

#### Example

```bash
gcc assembly.c -o a.out -g
gdb ./a.out
(gdb) b main
Breakpoint 1 at 0x1131: file assembly.c, line 6.
(gdb) r                                                           
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".
Breakpoint 1, main () at assembly.c:6
6               int i = 10;
(gdb) disassemble main
Dump of assembler code for function main:
   0x0000555555555129 <+0>:     endbr64
   0x000055555555512d <+4>:     push   %rbp
   0x000055555555512e <+5>:     mov    %rsp,%rbp
=> 0x0000555555555131 <+8>:     movl   $0xa,-0x8(%rbp)
   0x0000555555555138 <+15>:    movl   $0x14,-0x4(%rbp)
   0x000055555555513f <+22>:    mov    -0x4(%rbp),%eax
   0x0000555555555142 <+25>:    add    %eax,-0x8(%rbp)
   0x0000555555555145 <+28>:    mov    -0x4(%rbp),%eax
   0x0000555555555148 <+31>:    sub    %eax,-0x8(%rbp)
   0x000055555555514b <+34>:    mov    -0x8(%rbp),%eax
   0x000055555555514e <+37>:    imul   -0x4(%rbp),%eax
   0x0000555555555152 <+41>:    mov    %eax,-0x8(%rbp)
   0x0000555555555155 <+44>:    mov    -0x8(%rbp),%eax
   0x0000555555555158 <+47>:    cltd
   0x0000555555555159 <+48>:    idivl  -0x4(%rbp)
--Type <RET> for more, q to quit, c to continue without paging--
   0x000055555555515c <+51>:    mov    %eax,-0x8(%rbp)
   0x000055555555515f <+54>:    mov    $0x0,%eax
   0x0000555555555164 <+59>:    pop    %rbp
   0x0000555555555165 <+60>:    ret
End of assembler dump.
```

### start

Sets a temporary breakpoint on **main()** and starts executing a program under GDB.

```bash
start => break main + run
```

Still now we used the gdb with **break main** and run the source code using **run** command. Instead of that we can use **start** command and it will apply the break point at main and run the code.

### Command

#### Syntax

```bash
command breakpoint-number 
```

This specifies commands to run whenever the breakpoint is reached.

```bash
(gdb) b 16      # apply break at line 16
(gdb) info b    # get the information about breakpoints
(gdb) command 1 # apply the command for breakpoint 1
> print <variable name> # whenever breakpoint occurs we need to print the variable value
> end           # end the command
(gdb)run        # run the source code 
(gdb)c          # continue to see the value of the variable everytime break point occurs
```

  Type **"command"** for when breakpoint 2 is hit, one per line. End with a line saying just "end".

  We have used to print the variable value every time when the breakpoint occurs in the loop instead we can use this command to set what to do during the breakpoint.

## Core Dump

A **“core dump”** is a snapshot of memory at the instant when the program is crashed, typically saved in a file called **“core”**.

The core contains a memory contents of the process at the point of seg-fault including its

* Code segment
* Data segment
* Stack segment
* Heap segment

### Uses of Core Dump Files

--> Core dumps allows a user to save a crash for later analysis or off-site analysis, or comparison with other crashes.

--> For embedded computers, it may be impractical to support debugging on the computer itself, so analysis of a dump may take place on a different computer.

### Resource Limits

Every process has various limits associated with it. We can either set or get limit from the commands setrlimit and getrlimit

```bash
man setrlimit         # Use the manual to see the command setrlimit options
man getrlimit         # Use the manual to see the command getrlimit options
```

Bash offers a built-in ulimit through which we can edit these. Core-file max-size (ulimit -c/RLIMIT_CORE) controls the maximum core file size that can be generated when the process snaps.

```bash
$ ulimit -a                                                     # to see the list of all available resources
real-time non-blocking time  (microseconds, -R) unlimited     
core file size              (blocks, -c) 0                      # we can see that core file is 0, so it will not create a coredump file so we need to make some value
data seg size               (kbytes, -d) unlimited
scheduling priority                 (-e) 0
file size                   (blocks, -f) unlimited
pending signals                     (-i) 30989
max locked memory           (kbytes, -l) 65536
max memory size             (kbytes, -m) unlimited
open files                          (-n) 1048576
pipe size                (512 bytes, -p) 8
POSIX message queues         (bytes, -q) 819200
real-time priority                  (-r) 0
stack size                  (kbytes, -s) 8192
cpu time                   (seconds, -t) unlimited
max user processes                  (-u) 30989
virtual memory              (kbytes, -v) unlimited
file locks                          (-x) unlimited
$ ulimit -c unlimited                                           # we can set the core dump file to unlimited 
$ ./a.out                                                       # if we run the binary file, then core file will be created as core file size is unlimited now
$ ls                                                            # now we can see the core file in the current path 
```

**Note :** In wsl core is not creating properly so I found this article for helping with [core dump file creation issues](https://www.fromdual.com/hunting-the-core)

### Where is my core?

The core is dumped in the current working directory of the process.

### What to do with a core file

Core files can be examined with gdb, the GNU debugger. It can read the crash informations, and display (among other things) the backtrace that leads to the crash.

```bash
gdb /path/to/binary /path/to/core/file        # after this we can see the core file will show the exact line where segmentation fault is occured
```

After gdb finished to read the input and shows its prompt, execute:

```bash
(gdb) backtrace
# or 
(gdb) bt
```

GDB will then output the backtrace.

### Dumping core from outside the program

One possibility is with gdb, if available. This will let the program running:

```bash
(gdb) attach <pid>
(gdb) generate-core-file <optional-filename>
(gdb) detach
```

Another possibility is to signal the process. This will terminate it, assuming the signal is not caught by a custom signal handler:

```bash
$ gcc main.c -o a.out -g
$ ps -ef | grep a.out   # this will give a PID of the process a.out
$ kill -s SIGABRT <pid> # use the PID of the process a.out here
# now we can see the code dump file in the current folder, but its not working in WSL
```

### Dumping core from within the program

```bash
void dump_core_and_terminate(void)
{
    /*
     * Alternative:
     *   char *p = NULL; *p = 0;
     */
    abort();
} // This also not working in wsl
```

### Common Memory Issues in C Programming

Incorrect memory accesses  

* Using uninitialized variables
* Out-of-bounds memory accesses (read/write underflow/overflow bugs)
* Use-after-free/use-after-return (out-of-scope) bugs
* Double-free
* Leakage
* Undefined Behavior
* Data Races

### Out of bonds Memory Access

**Write overflow:** A bug where a write is attempted into a memory buffer after its last legally accessible location

**Write underflow:** A write is attempted into a memory buffer before its first legally accessible location

**Read underflow:** A read is attempted on a memory buffer before its first legally accessible location

**Read overflow:** A read is attempted on a memory buffer after its last legally accessible location

### free

Free utility is a command in linux which will display the current amount of memory used.

```bash
$ free
               total        used        free      shared  buff/cache   available
Mem:         7943328     1017512     6861552        3568      227740     6925816
Swap:        2097152           0     2097152

$ free | grep ^Mem      # to display only the first line
Mem:         7943328      966320     6912692        3568      227768     6977008
```

### Valgrind

**Note :** For the memory related issues especially dynamic memory allocation we need to use the ***valgrind*** because gcc will not show those errors in compilation.

#### About Valgrind

* Debugging Tool
* It is a wrapper around various tools for debugging and profiling. Best tool out of these is ***MemCheck*** that is used to find out memory leaks etc.

In order to use valgrind you have to include debugging information that is you should compile the application with -g option if you are using gcc .

```bash
gcc -o 1 1.c -g
valgrind --tool=memcheck --leak-check=yes  ./1
```

#### Pros

Catches common memory bugs (UB) on dynamically allocated memory regions

* Using Uninitialized Variables
* Out-of-bounds memory access(read/write underflow/overflow bugs)
* Use-after-free/use after return(out of scope) bugs
* Double free
* Leakage

#### Cons

**Performance:** target software may run up to 10 to 30 times slower when run under Valgrind.

Memory footprint: each allocation within the target program requires Valgrind to make a memory allocation as well (making running Valgrind on highly-resource-constrained embedded Linux systems difficult).

In order to see the call stack with line-number information, a recompile/build with the -g flag is required.

```bash
$ sudo apt install valgrind     # to install valgrind
$ gcc 1.c -o a.out -g           # compile the source code with debug flag
$ valgrind --tool=memcheck --leak-check=yes ./a.out     # use the valgrind with tool as memcheck and leak check enabled 
==28366== Memcheck, a memory error detector
==28366== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==28366== Command: ./a.out
==28366== 
==28366== 
==28366== HEAP SUMMARY:
==28366==     in use at exit: 35 bytes in 2 blocks
==28366==   total heap usage: 3 allocs, 1 frees, 47 bytes allocated
==28366== 
==28366== 16 bytes in 1 blocks are definitely lost in loss record 1 of 2
==28366==    at 0x4846828: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==28366==    by 0x1091A6: main (1.c:16)
==28366== 
==28366== 19 bytes in 1 blocks are definitely lost in loss record 2 of 2
==28366==    at 0x4846828: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==28366==    by 0x10917E: main (1.c:8)
==28366== 
==28366== LEAK SUMMARY:
==28366==    definitely lost: 35 bytes in 2 blocks
==28366==    indirectly lost: 0 bytes in 0 blocks
==28366==      possibly lost: 0 bytes in 0 blocks
==28366==    still reachable: 0 bytes in 0 blocks
==28366==         suppressed: 0 bytes in 0 blocks
==28366== 
==28366== For lists of detected and suppressed errors, rerun with: -s
==28366== ERROR SUMMARY: 2 errors from 2 contexts (suppressed: 0 from 0)
$ cat -n 1.c    # to see the source code with line numbers we use -n flag
```

## What is strace?

strace stands for system call tracer. It is a debugging tool that

* Monitors the system calls used by a program and
* All the signals it receives.

System calls are used by userspace applications when they need to do something that requires the kernel.

#### What it does

* Learn which system calls a program make

* Find those system calls that fail together with error code

* Find which files a program opens

* Find out what syscalls a running program is making, for example to see if it is struck in a loop

Using strace is quite simple. There are two ways to let strace monitor a program.

#### Method 1

```bash
$ strace program_name # Ex: $ strace ls
$strace pwd
```

**Reading strace output:** Each line in the output represents a system call.

They follow the format:

```bash
system_call(argument1, argument2, ... ) = return_value 
```

Errors (typically a return value of -1) have the errno symbol and error string appended.

```bash
open("/foo/bar", O_RDONLY) = -1 ENOENT (No such file or directory)
```

strace emits its entire output to stderr. So if we want to redirect the strace to a file, then we need to make sure to redirect from strace 2 to filename.

```bash
strace pwd 2> file.txt # 2 represents standard error
```

#### Method 2

If we want to monitor a process which is currently running we can attach to the process using –p option

```bash
strace –p <pid-of-the-application>
dd if=/dev/zero of=/dev/null bs=1 count=500k
strace dd if=/dev/zero of=/dev/null bs=1 count=500k
```

#### When Is strace Useful?

strace is very useful while debugging crashes.  Some scenarios where strace can be helpful are –

* When you don't have source code

* Program behaving poorly

* Nothing in the log files

* Nothing in stdout

* No ports responding

* Don't want to open gdb

* Debugging why an installation crashes on a machine.

* Debugging random crashes that are most probably due to the program running out of memory or due to it requesting an arbitrarily large chunk of memory.

* Finding out how the program interacts with the file system.

* Debugging crashes reproducibly only on one machine.

* Debugging crashes in unfamiliar code or in cases when sources are unavailable.

Strace may provide you with valuable information for many problem cases.For example: which config files really were read, which was the last file or shared library read before your
program crashed, and so on.

```bash
$ strace ./a.out
execve("./a.out", ["./a.out"], 0x7ffd1a441330 /* 75 vars */) = 0
brk(NULL)                               = 0x5624ecf6c000
mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7b158a46a000
access("/etc/ld.so.preload", R_OK)      = -1 ENOENT (No such file or directory)
openat(AT_FDCWD, "/etc/ld.so.cache", O_RDONLY|O_CLOEXEC) = 3
fstat(3, {st_mode=S_IFREG|0644, st_size=29087, ...}) = 0
mmap(NULL, 29087, PROT_READ, MAP_PRIVATE, 3, 0) = 0x7b158a462000
close(3)                                = 0
openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libc.so.6", O_RDONLY|O_CLOEXEC) = 3
read(3, "\177ELF\2\1\1\3\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0\220\243\2\0\0\0\0\0"..., 832) = 832
pread64(3, "\6\0\0\0\4\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0"..., 784, 64) = 784
fstat(3, {st_mode=S_IFREG|0755, st_size=2125328, ...}) = 0
pread64(3, "\6\0\0\0\4\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0"..., 784, 64) = 784
mmap(NULL, 2170256, PROT_READ, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7b158a200000
mmap(0x7b158a228000, 1605632, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x28000) = 0x7b158a228000
mmap(0x7b158a3b0000, 323584, PROT_READ, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1b0000) = 0x7b158a3b0000
mmap(0x7b158a3ff000, 24576, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1fe000) = 0x7b158a3ff000
mmap(0x7b158a405000, 52624, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0x7b158a405000
close(3)                                = 0
mmap(NULL, 12288, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7b158a45f000
arch_prctl(ARCH_SET_FS, 0x7b158a45f740) = 0
set_tid_address(0x7b158a45fa10)         = 51622
set_robust_list(0x7b158a45fa20, 24)     = 0
rseq(0x7b158a460060, 0x20, 0, 0x53053053) = 0
mprotect(0x7b158a3ff000, 16384, PROT_READ) = 0
mprotect(0x5624d951e000, 4096, PROT_READ) = 0
mprotect(0x7b158a4a2000, 8192, PROT_READ) = 0
prlimit64(0, RLIMIT_STACK, NULL, {rlim_cur=8192*1024, rlim_max=RLIM64_INFINITY}) = 0
munmap(0x7b158a462000, 29087)           = 0
exit_group(0)                           = ?
+++ exited with 0 +++
```

#### What are all these calls between execve() and write()?

They take care of connecting all of the standard C libraries before the main program starts.

They basically set up the runtime. If you look at them carefully you’ll see that they walk through a series of possible files, check to see if they are accessible, open them, map them into a memory location, and close them.

#### Redirecting the output to a file

Viewing data in the terminal is one thing, but sometimes we need to record the data to an file so we can analyze it later.

Using -o option we can redirect the complex output of strace into a file.

```bash
strace -o <output-file-name> <program-name>
strace -o empty-trace ./1     # both the empty trace and print trace will have same output except print trace has some print related system calls. 
strace -o print-trace ./2
vimdiff empty-trace print-trace
```

#### Generate statistics for System Calls

Sometimes, we only want to look at which system calls were made by the program and how many system calls of same type were made.These statistics can be used to identify the most commonly used system calls by the program.
Using –c option strace provides summary information on executing a program.

It provides information like number of times a system call is used,
time spent executing various system calls, number of times errors returned as shown below.

```bash
$ strace -c <command>
# '-C' - prints the regular output + stats
$ strace -C <command>
```
