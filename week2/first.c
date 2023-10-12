#include <stdio.h>
int main()
{
    char name[15];
    int age;
    // stop trying to get me to write comments im too lazy im not gonna do the notepad either <3
    printf("enter ur name pls: ");
    scanf("%s", name);
    printf("your name is %s\n", name);
    printf("enter ur age or I'll steal ur data: ");
    scanf("%d", &age);
    printf("ur %i years old bro\n", age);
    return 0;
}