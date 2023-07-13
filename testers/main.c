#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "radical.h"
#include "profit.h"
//#include "structure.h"

// Работа с данными, в т. ч. модулями

int main(void) {
    struct Point p1;
    int x = 22;
    float y = x*x + x*.33 + 2;
    printf("%.2f\n", y);

    printf("----------\n");
    float coupon = 32.84;
    int payments_per_year = 4;
    float price = 1032.74;
    float profit = profitability(coupon, payments_per_year, price);
    printf("The profit of bond: %.2f %s \n", profit, "%");
    printf("----------\n");

    int a = 100;
    printf("The root of number %d is %.1f\n", a, radical(a));
    printf("----------\n");
    
    int c = 25;
    int* uc = &c;
    printf("%ls\n", uc);

    p1.x = 10;
    p1.y = 20;

    printf("Coords: (%d, %d)\n", p1.x, p1.y);

	FILE* file = fopen("text.dat", "r");
	if (file == NULL) {
		printf("Error to open");
		return 1;
	}
	
	struct drei_t* root = NULL;

    int lineNumber = 1;
    char line[100];
    while (fgets(line, sizeof(line), file) != NULL) {
          struct drei_t* newData = createLineData(lineNumber, line);
          addLineData(&root, newData);
          lineNumber++;
    }
  
    fclose(file);
	
	printLineData(root);
}

struct drei_t {
	int numRow;
	char *content;
	struct drei_t* next;
};

typedef struct drei_t drei_t;

struct drei_t* createRow(int rowNumber, const char* content) {
    struct drei_t* newNode = (struct drei_t*)malloc(sizeof(struct drei_t));
    newNode->numRow = rowNumber;
    newNode->content = strdup(content);
    newNode->next = NULL;
    return newNode;
}

void printLineData(struct LineData* node) {
    while (node != NULL) {
        printf("Line %d: %s", node->lineNumber, node->content);
        node = node->next;
    }
}

