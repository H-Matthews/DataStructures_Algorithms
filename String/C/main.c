#include <stdio.h>
#include <stdlib.h>

#include "String.h"

char* getLine();

int main(void)
{

    printf("Enter your Name: ");
    char* line = getLine();

    String s2 = init();
    printString(s2);

    String s1 = allocateString(line);
    free(line);

    printf("String Size:%ld, String Capacity:%ld\n", s1.size, s1.capacity);
    printString(s1);

    free(s1.data);
    return 0;
}

// Returns dynamically allocated char array
// Programmer is responsible for unallocating memory
char* getLine()
{
    size_t arraySize = 16;
    char* buffer = malloc(sizeof(char) * arraySize);
    if(buffer == NULL)
    {
        perror("Could not allocate memory");
        return buffer;
    }

    // Gets a character from the keyboard until a '\n' is encountered
    // Resizes the buffer as needed
    char* charIterator = buffer;
    int character;
    int capacity = 0;
    int bytes = 0;
    while( (character = getchar() ) != '\n')
    {
        // Add character to buffer
        *(charIterator) = character;
        charIterator++;

        // IF capacity equals SIZE, allocate more memory
        if(++capacity == arraySize)
        {
            // Reallocate Memory
            arraySize *= 2; 
            bytes = sizeof(char) * arraySize;
            buffer = realloc(buffer, bytes);

            // Re-adjust iterator to the correct memory address
            charIterator = buffer + capacity;

            if(buffer != NULL)
                printf("Allocated more bytes:%d\n", bytes);
        }
    }

    buffer[capacity] = '\0';

    return buffer;
}