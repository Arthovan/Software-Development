# Compilation of pthreads
*   Ex :  gcc -pthread main.c -o main
## API's
*   **pthread_create()**
    *   Syntax : pthread_create(thread, attr, routine, arg).
    *   To create a new thread
*   **pause()**
    *   It will stop the execution of the main thread and wait for child threads to finish execution
*   **pthread_join()**
    *   It will halt the execution of the main thread and wait for child thread to thread join the main thread. Continues execution of the main thread where it left halt. If child thread didnt join the main thread then the child thread resources wont be freed.
*   **pthread_detach()**
    *   It creates a detached thread where the thread wont have to join the main thread, it can run and die without returning to any thread. Once died its resources are released automatically by kernel.
*   **pthread_exit()**
    *   It terminates the calling thread. This doesnt affect the othre threads.
## Thread Resources
*   OS allocates resources to threads - Memory, CPU, access to hardware etc
*   All threads are siblings, there is no parent-child(having privileges) relationship between threads of the same process, no hierarchy.
*   Every threads has its own lifecycle - birth, live and death are independent of other threads in the system 
    *   **One Exception :** When main thread of a proces dies - all other threads of a process are also terminated, vive versa is not true.
*   Multiple Threads of the processes share same virtual address space of a process.
    *   Resources allocated by one thread is visible to rest of the others.
    *   Heap Memory, Sockets, File Descriptors etc, Global Variables.
    **Note :** What threads do not share is the stack memory, every thread has its own stack memory.

## Joinable and Detached Thread
* A thread when created (pthread_create), it can be created in one of the two modes
    *   Joinable thread
    *   Detached thread
### Joinable Thread
*   Lets consider a main() thread created a thread T using pthread_create(). In this scenario main() thread runs separately and child thread T runs separately, we used pthread_join() in the main thread some where down the program.
*   Then the main() thread blocks there and wait until the thread T come back and join it (it can join either by return from thread or pthread_exit(0) call on it). Resources of thread T will be released only when it joins the caller thread (main() thread in our case.) then onlyt the main() resumes further.

    **Note :**
    1.  Resources of the Joinable Thread are not released until it joins the parent thread.
    2.  A joinable thread can be converted into detached thread while it is running or vice-versa.
    3.  By default, thread runs on joinalbe mode.
    4.  Joinable thread may return the result to joinee thread.

### Detached Thread
*   As us like joinable thread,lets consider a main() thread created a detached thread T using pthread_create(). In this scenario main() thread runs separately and child thread T runs separately.
*  Once the thread T finishes either pthread_exit() or simply finishes its work. All resources of the thread are released by the kernels process manager immediately.

    **Note :**
    1.  Resources of the Detached Thread are as soon as thread terminates.
    2.  A detached thread can be converted into joinable thread while it is running or vice-versa.
    3.  Detached thread do not return any result to Joinable thread, they work and then die without telling anybody.
