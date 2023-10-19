#include <stdio.h>
#include<ctype.h>

float fahr_to_celsius (float f_temp) //takes temperature in farenheit as an input (float), returns temp in celsius as a float
{
    float c_temp;
    c_temp = (f_temp - 32)/1.8;
    return c_temp;
}

float fahr_to_kelvin (float f_temp) //input farenheit as float, convert to kelvin & return as float
{
    float k_temp;
    k_temp = fahr_to_celsius(f_temp) + 273.15;
    return k_temp;
}

float fahr_to_newton (float f_temp) //input farenheit as float, convert to newton & return as float
{
    float n_temp;
    n_temp = fahr_to_celsius(f_temp) * 0.33;
    return n_temp;
}

int main ()  //main function
{
    float fahrenheit; //initialises fa as float
    char option;

    printf ("Enter a temperature to convert in Fahrenheit:\n");
    scanf ("%f", &fahrenheit); //stores input in variable "fahrenheit"

    printf ("\n");
    printf ("Select A to convert to Celsius\n");
    printf ("Select B to convert to Kelvin\n");
    printf("Select C to convert to Newton\n");
    printf ("Select Q to quit\n");

    scanf(" %c", &option); //allows the user to choose a, b or q, stores in variable "option"

    option = toupper(option);

    switch (option)
    {
        case 'A': printf ("Converted to degrees Celsius: %f\n", fahr_to_celsius(fahrenheit)); //if user has input "A" (option=="A"), call cel function and print answer
                  break;

        case 'B': printf ("Converted to Kelvin: %f\n", fahr_to_kelvin(fahrenheit)); //as above but for kelvin
                  break;
        case 'C': printf("Converted to Newton: %f\n", fahr_to_newton(fahrenheit));

        case 'Q': break;

        default:  break;
    }

    return 0;
}