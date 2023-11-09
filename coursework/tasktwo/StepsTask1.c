#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// read file function used in previous programming lessons (read_from_file_function.c) 
FILE *open_file(char *filename, char *mode){
    FILE *file = fopen(filename, mode);
    if (file == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    return file;
}

// Define any additional variables here
FITNESS_DATA dataArray[10000];
int counter = 0;
char buffer[10];



// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
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

// Complete the main function
int main() {
    /*success criteria:
    - make menu
    - cope with incorrect file name
    - display total number of records
    - date & time of fewest steps
    - date and time of most steps
    - mean step count
    - longest continuous period
    */

    //import the file and open it
    char *filename = "FitnessData_2023.csv";
    FILE *file = open_file(filename, "r");

    int buffer_size = 100;
    char line_buffer[buffer_size];

    //reads each line in the file
    while (fgets(line_buffer, buffer_size, file) != NULL)
    {

        //splits line into date, time and step count, stores these in 3d dataArray and stores step count as buffer to cast to int
        tokeniseRecord(line_buffer, ",", dataArray[counter].date, dataArray[counter].time, buffer);

        //casts buffer to int so step count can be stored
        dataArray[counter].steps = atoi(buffer);
        
        
        counter++;

    }
    
    //prints number of lines in the file
    printf("Number of records in file: %d\n", counter);

    //prints date, time and steps for first 3 records
    for(int i = 0; i<3; i++){
        printf("%s/%s/%d\n", dataArray[i].date, dataArray[i].time, dataArray[i].steps);
    }

    //close the file
    fclose(file);

}