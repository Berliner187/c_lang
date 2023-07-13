#include <stdio.h>

void print_char() {
	char a = getchar();
	
	putchar(a);
	printf("\n");
	printf("You entered: %c\n", a);
}
