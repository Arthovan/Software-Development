# Compilation of pthreads
*   Ex :  gcc -pthread main.c -o main

*   /* 
    *   OS allocates resources to threads - Memory, CPU, access to hardware etc
    *   All threads are siblings, there is no parent-child(having privileges) relationship between threads of the same process, no hierarchy
    *   Every threads has its own lifecycle - birth, live and death are independent of other threads in the system
            #   One Exception : when main thread of a proces dies - all other threads of a process are also terminated, vive versa is not true.

    *   Multiple Threads of the processes share same virtual address space of a process
            #   Resources allocated by one thread is visible to rest of the others
            #   Heap Memory, Sockets, File Descriptors etc, Global Varibles
    
    *   What threads do not share is the stack memory, every thread has its own stack memory.
    */
