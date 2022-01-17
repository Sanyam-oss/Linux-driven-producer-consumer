# Linux-driven-producer-consumer

Running Instructions
----------------------

# Testing System Call
    
- Open linux terminal in the current directory

a) To run P program
    
    >  make p

b) To run C program 
    
    >  make c 

- This will give us our desired output on the terminal and will also print if  system calls executed successfully or not.

- Run

    > make clean in current directory to clean the executable file of our .c file


Logic
------

1. Firstly we declared our 3 system calls init , reader , writer in the /home/kern/build/linux-5.14.5/arch/x86/entry/syscalls/syscall_64.tbl file.

2. After that we defined their implementations in /home/kern/build/linux-5.14.5/kernel/sys.c file using SYSCALL_DEFINE();

3. In sys.c we firstly declared a long* pointer to our queue and initialised front and back index of this queue as -1 .

4. We then declared a mutex - Lock using static method : static DEFINE_MUTEX(lock);

5. Now to initialise our queue we first call init syscall from our P Program that allocates fixed number of bytes to our queue using kmalloc kernel fxn.

6. After that we call our syscall writer from P program with parameter as a random long number to enqueue it in our queue.

7. In writer syscall definition we first lock our mutex and call enq fxn to enqueue the number passed in our queue. nd then unlock the mutex.

8. We repeat similar procedure for the reader syscall which we call from the C program.

9. We used mutex here because there was a access to some shared memory which could cause some race type conditions otherwise.

10. Can also use semaphores instead of mutexes here.

11. Implemented a circular queue of length 100 ie can store at max 100 long type data objects.

12. System calls return -1 in case of any errors, to provide error handling in the P and C programs.

13. To generate random number we first open the /dev/urandom file in Read only mode and then read 8 bytes which are stored in num variable.

Source files modified :
-------------------------

1. /home/kern/build/linux-5.14.5/arch/x86/entry/syscalls/syscall_64.tbl

2. /home/kern/build/linux-5.14.5/kernel/sys.c


Resources Used :
----------------

1. https://www.kernel.org/doc/htmldocs/kernel-locking/Examples.html
2. https://stackoverflow.com/questions/40309582/kernel-module-compiler-error-function-declaration-isn-t-a-prototype-werror-st
3. https://embetronicx.com/tutorials/linux/device-drivers/linux-device-driver-tutorial-mutex-in-linux-kernel/#Mutex_in_Linux_Kernel
