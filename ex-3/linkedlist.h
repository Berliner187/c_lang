#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "line_data.h"

void addLineData(struct LineData** root, struct LineData* newData);
void printLineData(struct LineData* node);
void freeLineData(struct LineData* node);

#endif

