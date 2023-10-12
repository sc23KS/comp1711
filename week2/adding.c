#include <stdio.h>
int main(){
    float height;
    float width;
    float area;
    printf("enter height: ");
    scanf("%f", &height);
    printf("enter width: ");
    scanf("%f", &width);
    area = height * width;
    printf("The area is %g\n", area);
    printf("Hello world!\n");
    int num1;
    int num2;
    printf("number1: ");
    scanf("%i", &num1);
    printf("number2: ");
    scanf("%i", &num2);
    printf("%i\n", num1+num2);
    printf("char size: %lu\n", sizeof(char));
    printf("int size: %lu\n", sizeof(int));
    printf("float size: %lu\n", sizeof(float));
    printf("double size: %lu\n", sizeof(double));
    float radius;
    printf("enter radius: ");
    scanf("%f", radius);
    printf("%g", 3.14*radius*radius);
}