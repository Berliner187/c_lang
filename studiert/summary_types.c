#include <stdio.h>

int sum;
int summary() {
	sum = sizeof(int) + sizeof(float) + sizeof(double);
	printf("%d\n", 0);
	return sum;
}
