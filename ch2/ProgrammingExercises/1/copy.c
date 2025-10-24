#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char*argv[]) {
	printf("Enter source file: ");
	char source[1000];
	scanf("%s", source);
	printf("Enter destination file: ");
	char dest[1000];
	scanf("%s", dest);

	FILE *fp = fopen(source, "r");

	if(fp == NULL) {
		printf("Failed to open %s...\nAborting...\n", source);
		return 1;
	}

	FILE *fp2 = fopen(dest, "w");

	if(fp2 == NULL) {
		printf("Failed to open %s...\nAborting...\n", dest);
		return 1;
	}

	int ch;

	while((ch = fgetc(fp)) != EOF)
		fputc(ch, fp2);

	fclose(fp);
	fclose(fp2);

	return 0;
}
