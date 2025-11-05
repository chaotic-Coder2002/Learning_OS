/*
   More on the fork() system call
 */

#include<stdio.h>
#include<unistd.h>

int main(int argc, char* argv[]) {

	puts("Process execution begins...");

	pid_t pid1 = fork();
	pid_t pid2 = fork();
	printf("Hello! %d, %d\n", pid1, pid2);

	return 0;
}
