#include <stdio.h>

int main() {

    int mark;

    printf ("Enter the mark: \n");
    scanf ("%d", &mark);
    if (mark<0 || mark>100){
        printf("invalid mark\n");
        return 0;
    }
    if (mark == 0)
    {
        printf ("The mark of %d is zero\n", mark);
    }
    else if (mark < 40)
    {
        printf ("The mark of %d is a fail\n", mark);
    }
    else if (mark>70){
        printf("the mark of %d is a first. WAHOO\n", mark);
    }
    else if (mark>60){
        printf("the mark of %d is a 2:1 my dude\n", mark);
    }
    else
    {
        printf ("The mark of %d is a pass\n", mark);
    }

    return 0;
}