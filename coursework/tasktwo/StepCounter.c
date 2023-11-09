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
    */

    //make menu loop until quit is selected
    while(true){
        printf("Menu Options:\nA: Specify the filename to be imported\nB: Display the total number of records in the file\nC: Find the date and time of the timeslot with the fewest steps\nD: Find the date and time of the timeslot with the largest number of steps\nE: Find the mean step count of all the records in the file\nF: Find the longest continuous period where the step count is above 500 steps\nQ: Quit\n");
        scanf("%c", tolower(choice));
        if (choice = "a"){
            printf("Input filename:\n");
            scanf("%s", filename);
        }
        else if (choice = "b"){
            FILE *file = open_file(filename, "r");
            
        }
    }
}
