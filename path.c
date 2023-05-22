#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
char* _path();

int main()
{
    char* directories = _path();
    printf("%s\n", directories);
    free(directories);
    return 0;
}

*/

char* _path()
{
    char* ptrr;
    char* ptr;
    int i = 0;
    char* result = (char*)malloc(sizeof(char)); // Allocate memory for the result
    result[0] = '\0'; // Initialize the result as an empty string

    ptrr = getenv("PATH");
    ptr = strdup(ptrr);

    while (ptr[i] != '\0')
    {
        if (ptr[i] == ':')
        {
            size_t len = strlen(result);
            result = (char*)realloc(result, len + 2); // Reallocate memory for a new character and the newline
            strcat(result, "\n"); // Append a newline character to the result
        }
        else
        {
            size_t len = strlen(result);
            result = (char*)realloc(result, len + 2); // Reallocate memory for a new character and the null terminator
            char temp[2] = {ptr[i], '\0'}; // Create a temporary string for the current character
            strcat(result, temp); // Append the character to the result
        }
        i++;
    }

    free(ptr);

    return result;
}

