#include "FitnessDataStruct.h"

//struct, helper function and file function all moved to header
//add global variables (file names & array)

FITNESS_DATA dataArray[10000];
int counter = 0;
char buffer[10];
char choice;
char *filename = NULL;

int main(){
    /*success criteria:
    - make menu
    - cope with incorrect file name
    - display total number of records
    - date & time of fewest steps
    - date and time of most steps
    - mean step count
    - longest continuous period
    - close file
    */

    //make menu loop until quit is selected
    while(1){
        printf("Menu Options:\nA: Specify the filename to be imported\nB: Display the total number of records in the file\nC: Find the date and time of the timeslot with the fewest steps\nD: Find the date and time of the timeslot with the largest number of steps\nE: Find the mean step count of all the records in the file\nF: Find the longest continuous period where the step count is above 500 steps\nQ: Quit\n");
        scanf("%c", tolower(choice));

        //takes the name of the file as an input
        if (choice = "a"){
            printf("Input filename:\n");
            scanf("%s", filename);
        }
        //open the file
        FILE *file = open_file(filename, "r");

        int buffer_size = 100;
        char line_buffer[buffer_size];
        counter = 0;

        while (fgets(line_buffer, buffer_size, file) != NULL){

        //splits line into date, time and step count, stores these in 3d dataArray and stores step count as buffer to cast to int
        tokeniseRecord(line_buffer, ",", dataArray[counter].date, dataArray[counter].time, buffer);

        //casts buffer to int so step count can be stored
        dataArray[counter].steps = atoi(buffer);
        
        counter++;
        }


        if (choice = "a"){
            //prevents option a being unrecognised
            continue;
        }
        else if (choice = "b"){
            printf("Total records: %i", counter);
        }
        else if (choice = "c"){
            //loop each item in array, from index 0 to counter, linear search for lowest value, print date & time at this index
        }
        else if (choice = "d"){
            //same as c but find largest value
        }
        else if (choice = "e"){
            //loop each item in array, index 0 to counter, adding step counts then divide by counter, round as appropriate (DO NOT TRUNCATE)
        }
        else if (choice = "f"){
            //todo
        }
        else if (choice = "q"){
            //todo return 0 and quit
        }
        else{
            //todo: they didn't choose a valid option
        }
    }
}