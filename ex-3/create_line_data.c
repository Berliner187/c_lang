#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "create_line_data.h"

struct LineData* createLineData(int lineNumber, char* content) {
    struct LineData* newNode = (struct LineData*)malloc(sizeof(struct LineData));
    newNode->lineNumber = lineNumber;
    newNode->content = content;
    newNode->next = NULL;
    return newNode;
}

