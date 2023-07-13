#ifndef LINE_DATA_H
#define LINE_DATA_H

// Структура (3 линии, из задания)
struct LineData {
    int lineNumber;
    char *content;
    struct LineData* next;
};

struct LineData* createLineData(int lineNumber, char* content);

#endif
