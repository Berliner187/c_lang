#include <stdio.h>

#include "summary_types.h"

int main(void) {
	printf("int: %ld \n", sizeof(int));
	printf("float: %ld \n", sizeof(float));
	printf("double: %ld \n", sizeof(double));
	printf("char: %ld \n", sizeof(char));
	
	printf("%d\n", summary());
	return 0;
}

