#include <stdio.h>

void calc_height() {
	printf("КАЛЬКУЛЯТОР ПЕРЕВОДА ИЗ ЦЕЛЬСИЯ В ГРАДУСЫ \n\n");
	printf("Введите температуру в Цельсиях: ");
	
	float temp_c;
	scanf("%f", &temp_c);
	
	float temp_f = temp_c * 9 / 5 + 32;
	printf("Температура в Фарегейтах: %.2f \n", temp_f);
}
