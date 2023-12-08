//prevents errors where the header is included multiple times (if it's already defined, do not overwrite)
#ifndef FITNESSDATASTRUCT_H
#define FITNESSDATASTRUCT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//definition of FITNESS_DATA struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

//helper function
void tokeniseRecord(const char *input, const char *delimiter, char *date, char *time, char *steps);
void tokeniseRecord(const char *input, const char *delimiter, char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {
        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

}


//function to open files
FILE *open_file(char *filename, char *mode);
FILE *open_file(char *filename, char *mode)
{
    FILE *file = fopen(filename, mode);

    if (file == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    return file;
}

#endif