#include<stdio.h>

struct birthday {
	int day;
	int month;
	int year;
};

int main(int argc, char*argv[]) {
	struct birthday a = {
		.day = 10,
		.month = 2,
		.year = 1999
	};

	char *b = (char*) &a; // typecasting the struct variable `a` into a character array

	for(int i = 0; i < sizeof(a); i++)
		printf("%d ", (unsigned char)b[i]); // accessing each byte!

	puts("");
	return 0;
}
