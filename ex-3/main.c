#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "line_data.h"
#include "linkedlist.h"

int main(void) {
    FILE* file = fopen("input.txt", "r");

    struct LineData* root = NULL;

    int lineNumber = 1;
	char line[100];
	while (fgets(line, sizeof(line), file) != NULL) {
    	struct LineData* newData = createLineData(lineNumber, strdup(line));
    	addLineData(&root, newData);
    	lineNumber++;
	}

    fclose(file);
    printLineData(root);
    freeLineData(root);
    return 0;
}

