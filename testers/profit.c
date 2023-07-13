#include <stdio.h>

float coupon_income;
float profit_percent;

int payment_sum();

float profitability (float coupon, int num_of_payments, float price) {
    coupon_income = coupon * num_of_payments;
    profit_percent = coupon_income * 100 / price;

    printf("%d\n", payment_sum());

    return profit_percent;
}

int payment_sum() {
    // int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    // printf("%d\n", int *);
    for (int i=0; i < 10; i++) {
    	printf("%d", i);
    }
    return 0;
}
