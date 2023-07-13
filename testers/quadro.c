#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <time.h>
#include <unistd.h>

int main(void) {
	// Возведение в степень и обратно
	
	double time_spent = 0.0;
    clock_t begin = clock();

	long num = 0;
	//int *array_pows;

	long to_pow;
	long range = pow(2, 18);

	//array_pows = (int *)malloc(range * sizeof(int));

	//if (array_pows == NULL) {
    //   printf("Ошибка");
	//   return 1;
	//}

	int ar_index = 0;
	for (int i = 1; i < range + 1; i++) {
		to_pow = pow(i, 2);
		printf("%d (%ld) \n", i, to_pow);

		//array_pows[ar_index] = to_pow;
		if (i == range) {
			num += to_pow;
		}
	}

	// Вывод значений массива
    //for (int j = 0; j < range; j++) {
    //    printf("%d\n", array_pows[j]);
    //}
	
	float radical;
	for (int i = num; i > 0; i--) {
		radical = pow(i, 0.5);
		if ( (pow(radical, 2) == i) && ( roundf(radical)) ) {
			printf("%d (%.0f) \n", i, pow(i, 0.5));
		}
	}
	
	for (int i = num; i > 0; i--) {
		int number = pow(i, 0.5);
		int buffer;
		int old_buffer;

		buffer = number;
		if (old_buffer != buffer) {
			old_buffer = buffer;
			//printf("%d\n", number);
		}
		else {
		}
		//printf("%.0f\n", pow(i, 0.5));
	}

    //free(array_pows);

	clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
	printf("The elapsed time is %f seconds\n", time_spent);

	return 0;
}

