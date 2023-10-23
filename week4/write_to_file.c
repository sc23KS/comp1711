#include <stdio.h>

int main()
{
    char *filename = "data.txt";

    FILE *file = fopen(filename, "w"); // or "a", "w+", "a+"
    if (file == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    int number;
    int num_lines;
    int total = 0;

    printf("How many lines u wanna do?\n");
    scanf("%d",&num_lines);
    
    printf("Type %d numbers: ", num_lines);
    
    for (int i = 0; i < num_lines; i++)
    {
        scanf("%d", &number);
        fprintf(file, "%d\n", number);
        total+=number;
    }
    printf("mean of ur nums is: %d\n", total/num_lines);
    fprintf(file, "%f", total/num_lines);

    char stringz[20];
    num_lines = 0;

    printf("How many lines u wanna do now?\n");
    scanf("%d",&num_lines);
    
    printf("Type %d strings (20 char max): ", num_lines);
    
    for (int i = 0; i < num_lines; i++)
    {
        scanf("%s", stringz);
        fprintf(file, "%s\n", stringz);
    }

    fclose(file);
    return 0;
}