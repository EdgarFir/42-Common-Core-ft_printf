#include <stdio.h>

int main()
{

	//printf("%#c");
	//printf("% c", 'c');
	printf("|%-c|\n", 'c');
	printf("|%10c|\n", 'c');
	printf("|%-5c|\n", 'c');
	printf("|%5c|\n", 'c');
	//printf("|%05c|\n", 'c');
	//printf("%+c");

	printf("\n|%05x|", 42);
	printf("\n|%#x|", 42);
	printf("\n|%-x|", 42);
	printf("\n|%.4x|", 42);
	printf("\n|%10x|\n", 42);

	int n = 42;
	void *p = NULL;
	printf("\n|%p|\n", &n);
	printf("|%p|\n", p);
	printf("|%-10p|\n", p);
	printf("|%20p|\n", &n);

	printf("\n|%s|\n", "Hello World!");
	printf("|%20s|\n", "Hello World!");
	printf("|%10.5s|\n", "Hello World!"); // pre < len(s) width = width - len.
	printf("|%-10.5s|\n", "Hello World!");

	printf("\n|%10u|\n", 42);
	printf("|%020u|\n", 42);
	printf("|%.10u|\n", 42);
	printf("|%-10u|\n", 42);
	printf("|%-10.10u|\n", 42);
	printf("|%010u|\n", 42); // 0 ignored with precision and -

	printf("\n|%+4.8i|\n", 42);
	printf("|%0+4i|\n", 42);
	printf("|%+4i|\n", 42);
	printf("|%- 10i|\n", 42);
	printf("|% 5i|\n", -42);
	printf("|% 4i|\n", 42);
	printf("|%0 5i|\n", -42);
	printf("|%0 4i|\n", 42);
	
}