#include <stdio.h>
#include <stdlib.h>
int main() {
    float total = 0;
    int lines = 0;
    char* filename = "data.txt";
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    
    int buffer_size = 100; //length of line to read (reads up to 100 chars per line)
    char line_buffer[buffer_size]; //a string which will hold each line as it's read in

    while (fgets(line_buffer, buffer_size, file) != NULL) { //while theres data left to read in the file (read into line buffer, up to buffer size, within the file, until no data left)
        printf("%d\n", atoi(line_buffer));
        lines++;
        total+=atoi(line_buffer);
    }
    printf("sum is %g over %d lines, average is %g\n", total, lines, total/lines);
    fclose(file);
    FILE *file2 = fopen(filename, "a");
    fprintf(file2, "%g", total/lines);
    fclose(file2);
}