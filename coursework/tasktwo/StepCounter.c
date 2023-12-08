#include "FitnessDataStruct.h"


//struct, helper function and file function all moved to header
//add global variables (file names & array)

FITNESS_DATA dataArray[10000];
int counter = 0;
char buffer[10];
char choice = 'u';
char filename[200] = "FitnessData_2023.csv";
int temp;
int savedIndex;

int main(){
    /*
    important stuff:
    - round result in choice=E
    - check file name input on choice=A
    success criteria:
    - make menu
    - cope with incorrect file name
    - display total number of records
    - date & time of fewest steps
    - date and time of most steps
    - mean step count
    - longest continuous period
    - close file
    - cast 'choice' to lower
    - hint for rounding: calculate as float, use format string with 0 decimal places as this will (should) round for me
    */

    //make menu loop until quit is selected
    while(1){
        printf("Menu Options:\nA: Specify the filename to be imported\nB: Display the total number of records in the file\nC: Find the date and time of the timeslot with the fewest steps\nD: Find the date and time of the timeslot with the largest number of steps\nE: Find the mean step count of all the records in the file\nF: Find the longest continuous period where the step count is above 500 steps\nQ: Quit\n");
        scanf(" %c", &choice);

        //casts choice to lowercase
        if(choice>=65 && choice<=90){
            choice+=32;
        }

        //gets the new file name, opens the file, reads it, stores the data in an array, closes the file
        if (choice == 97){ //a
            printf("Input filename:\n");
            scanf(" %s", filename);
            FILE *file = open_file(filename, "r");

            int buffer_size = 100;
            char line_buffer[buffer_size];
            counter = 0;
            //reads the data from the file into the array
            while (fgets(line_buffer, buffer_size, file) != NULL){

                //splits line into date, time and step count, stores these in 3d dataArray and stores step count as buffer to cast to int
                tokeniseRecord(line_buffer, ",", dataArray[counter].date, dataArray[counter].time, buffer);

                //casts buffer to int so step count can be stored
                dataArray[counter].steps = atoi(buffer);
        
                counter++;
            }
            fclose(file);
        }
        else if (choice == 98){ //b
            printf("Total records: %i\n", counter);
        }
        else if (choice == 99){ //c
            //loop each item in array, from index 0 to counter, linear search for lowest value, print date & time at this index
            temp = 99999;
            for(int i=0;i<counter;i++){
                if (dataArray[i].steps<temp){
                    temp = dataArray[i].steps;
                    savedIndex = i;
                }
            }
            printf("Fewest steps: %s %s\n", dataArray[savedIndex].date, dataArray[savedIndex].time);
        }
        else if (choice == 100){ //d
            temp = -1;
            for(int i=0;i<counter;i++){
                if (dataArray[i].steps>temp){
                    temp = dataArray[i].steps;
                    savedIndex = i;
                }
            }
            printf("Largest steps: %s %s\n", dataArray[savedIndex].date, dataArray[savedIndex].time);
        }
        else if (choice == 101){ //e
            //loop each item in array, index 0 to counter, adding step counts then divide by counter, round as appropriate (DO NOT TRUNCATE)
            temp = 0;
            for(int i=0; i<counter; i++){
                temp += dataArray[i].steps;
            }
            printf("KIM ROUND THIS NUMBER\nMean step count: %g\n", round(temp/counter));
        }
        else if (choice == 102){ //f
            //todo: find the longest period where steps is over 500
            //find streaks of 500+ steps, time taken and index where longest streak starts
            int longestStreak = 0;
            int currentStreak = 0;
            int streakStart = 0;
            int longestStreakStart = 0;
            for(int i=0; i<counter; i++){
                if (dataArray[i].steps>500){
                    //increment currentStreak
                    //if currentStreak WAS 0, streakStart = i
                    //continuously increments currentStreak, saving the index the streak starts, until the step count is 500 or less
                    if(currentStreak == 0){
                        streakStart = i;
                    }
                    currentStreak++;
                }
                else{
                    //end currentStreak
                    //if currentStreak > longestStreak, update longestStreak and longestStreakStart
                    if(currentStreak>longestStreak){
                        longestStreak = currentStreak;
                        longestStreakStart = streakStart;
                    }
                    currentStreak = 0;
                }
            }
            printf("Longest period start: %s %s\n", dataArray[longestStreakStart].date, dataArray[longestStreakStart].time);
            printf("Longest period end: %s %s", dataArray[longestStreakStart+longestStreak].date, dataArray[longestStreakStart+longestStreak].time);
        }
        else if (choice == 113){ //q
            //todo return 0 and quit
            return 0;
            break; //is this necessary? does "return 0" end the program?
        }
        else{
            printf("Invalid input, try again\n");
        }
    }
}
