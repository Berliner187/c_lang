#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linkedlist.h"

void addLineData(struct LineData** root, struct LineData* newData) {
    if (*root == NULL) {
        *root = newData;
    } else {
        struct LineData* current = *root;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newData;
    }
}

void printLineData(struct LineData* node) {
    while (node != NULL) {
        printf("Line %d: %s", node->lineNumber, node->content);
        node = node->next;
    }
}

void freeLineData(struct LineData* node) {
    struct LineData* temp;
    while (node != NULL) {
        temp = node;
        node = node->next;
        free(temp);
    }
}

