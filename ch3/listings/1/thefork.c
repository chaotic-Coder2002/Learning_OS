/*
   A new process is created by the fork() system call.
   The new process consists of a copy of the address space of the original process. This mechanism allows the parent process to communicate
   easily with its child process. Both processes (the parent and the child) continue execution at the instruction after the fork(), with
   one difference: the return code for the fork() is zero for the new (child) process, whereas the (non-zero) process identifier of
   the child is returned to the parent.


   [Address space of a process]: It's a range of virtual addresses that the OS assigns to a user or a separately running program.
   The range of virtual addresses in an address space starts at zero and can extend to the highest address permitted by the OS artchitecture.
 */






#include<stdio.h>
#include<sys/types.h> // for pid_t
#include<sys/wait.h> // for wait()
#include<unistd.h> // for fork() and execlp()

int main(int argc, char* argv[]) {
	pid_t pid;
	
	/* fork a child process */
	pid = fork();

	printf("My id is: %d\n", pid);

	if(pid < 0) {
		fprintf(stderr, "Fork failed");
		return 1;
	} else if(pid == 0) { // child process
		puts("I am the child");
		execlp("/usr/bin/ls", "ls", NULL);
	} else { // parent process
		// parent waits for the child to complete
		puts("I am the parent");
		wait(NULL);
		puts("Child Complete");
	}

	return 0;
}
