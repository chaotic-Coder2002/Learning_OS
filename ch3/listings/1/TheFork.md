# The `fork()` system call

* Program: <a href="https://github.com/chaotic-Coder2002/Learning_OS/blob/OS/ch3/listings/1/thefork.c">thefork.c</a>.

After a `fork()` system call, one of the two processes typically uses the `exec()` system call to replace the process's memory space with a new program.
The `exec()` system call loads a binary file into memory (destroying the memory image of the program containing the `exec()` system call) and starts its execution. In this manner, the two processes are able to communicateand then go their separate ways.

The parentcan then create more children; or if it has nothing else to do while the child runs, it can issue a `wait()` system call to move itself off the ready queue until the termination of the child. Because the call `exec()` overlays the process's address space with a new program, the call to `exec()` doesn't return control unless an error occurs.


---
