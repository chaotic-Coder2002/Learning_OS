#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>


int main(int argc, char* argv[]) {
	pid_t pid;

	puts("Hello from the single main process...\n");
	puts("Now, say \"Hello\" to my child...\n");

	pid = fork();

	if(pid < 0) {
		fprintf(stderr, "Fork failed");
		return 1;
	} else if(pid == 0) {
		char name[20];
		puts("Hello, I am the child...\n");
		printf("I would like to know your name please:");
		scanf("%s", name);
		printf("Hi %s!\n\n", name);
	} else {
		printf("Child's PID is %d\n\n", pid);

		pid_t pid2; // this was taken for demonstrating the pid and pid2 are the same
		int status;
		pid2 = wait(&status);

		printf("Process with pid %d terminated with exit status %d\n\n", pid2, status);
	}


	return 0;

}
