#include <stdio.h>
int main(){
    float num1, num2;
    printf("Please enter your first number then your second:\n");
    scanf("%f %f",&num1,&num2);
    printf("sum is %g\n",num1+num2);
    //the prompt did not ask me to give the user a chance to answer so I did not.
    printf("What's your favourite animal?\n");
    /* however if I were to allow the user to answer, I would do it like this: 
    char animal[30];
    scanf("%s",animal);
    printf("ur fav animals a %s",animal);
    */
    return 0;
    //errors in example code - answer is not given a type, comma missing in print statement
}