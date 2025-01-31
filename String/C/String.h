#include <stdio.h>

// Defines a Null Terminated String structure
typedef struct 
{
    char* data;

    size_t size;
    size_t capacity;
    size_t bytes;

} String;

String init();

String allocateString(char* buffer);

size_t length(String string);

void printString(String s1);

