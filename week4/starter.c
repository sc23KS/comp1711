#include <stdio.h>
int main()
{
    int array[10];
    float sum = 0;
    for (int i = 0; i < 10; i++)
    {
        printf("number %d:", i + 1);
        scanf("%d", &array[i]);
        sum += array[i];
    }
    for(int i=0;i<10;i++){
        printf("%d ", array[i]);
    }
    printf("\nmean is %g\n", sum / 10);
}