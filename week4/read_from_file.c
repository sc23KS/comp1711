#include <stdio.h>
#include <stdlib.h>

int main() {
    char* filename = "data.txt";
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    int buffer_size = 100; //length of line to read (reads up to 100 chars per line)
    char line_buffer[buffer_size]; //a string which will hold each line as it's read in

    while (fgets(line_buffer, buffer_size, file) != NULL) { //while theres data left to read in the file (read into line buffer, up to buffer size, within the file, until no data left)
        printf("%d\n", atoi(line_buffer)); //
    }

    fclose(file);
    return 0;
}