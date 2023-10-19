#include <stdio.h>

int main() {
    int a = -1;
    while (a>3 || a<0){
    printf("input ur option dude: ");
    scanf("%d",&a);
    }
    switch (a)
    {
        case 0:     printf ("Option 0 has been selected\n");
        break;

        case 1:     printf ("Option 1 has been selected\n");
        break;

        case 2: printf("option 2\n"); break;

        case 3: printf("option 3\n"); break;

        default:    printf ("A different option has been selected, try again\n");
    }
}