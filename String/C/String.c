#include "String.h"

#include <stdlib.h>

String init()
{
    String s1;
    s1.data = NULL;
    s1.bytes = 0;
    s1.capacity = 0;
    s1.size = 0;

    return s1;
}

String allocateString(char* buffer)
{
    String s1;

    // Initially, allocate 10 slots
    size_t capacity = 10;

    // Fillout String fields
    s1.capacity = capacity;
    s1.size = 0;
    s1.bytes = sizeof(char) * s1.capacity;
    s1.data = (char*)malloc(s1.bytes);

    if(s1.data == NULL)
    {
        perror("Allocation Failure");
        exit(1);
    }

    // Walk the String, copy each buffer index into the Strings data value
    char* bufferIt = buffer;
    char* stringIt = s1.data;
    int charCounter = 0;
    while(*(bufferIt) != '\0')
    {
        // Store buffer value in String 
        *(stringIt++) = *(bufferIt++);
        s1.size++;
        
        // Allocate more memory, always check capacity - 1 so we always have room for Null terminator
        if(s1.size == s1.capacity - 1)
        {
            s1.capacity *= 2;
            s1.bytes = sizeof(char) * s1.capacity;
            s1.data = realloc(s1.data, s1.bytes);

            // Readjust StringIt to the correct memory address
            stringIt = s1.data + s1.size;

            if(s1.data == NULL)
            {
                perror("Allocation Failure");
                exit(1);
            }
        }
    }

    // Assign last value to null terminator
    if(s1.size < s1.capacity)
    {
        s1.data[s1.size + 1] = '\0';
    }
    
    return s1;
}

size_t length(String string)
{
    size_t length = 0;
    if(string.data == NULL)
    {
        length = 0;
    }
    else 
    {
        length = string.size;
    }

    return length;
}

void printString(String s1)
{
    if(s1.capacity == 0)
    {
        perror("String was not allocated");
        return;
    }

    char* it = s1.data;
    while(*(it) != '\0')
    {
        putc(*(it++), stdout);
    }
    putc('\n', stdout);

    return;
}