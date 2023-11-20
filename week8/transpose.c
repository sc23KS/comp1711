#include <stdio.h>

int main(){
    int array[2][3] = {{1,2,3},{4,5,6}};
    int transposedArray[3][2];
    for(int row = 0; row<2; row++){
        for(int column = 0; column<3; column++){
            transposedArray[column][row] = array[row][column];
        }
    }
    printf("array:\n");
    for(int row = 0; row<2; row++){
        for(int column = 0; column<3; column++){
            printf("%d ", array[row][column]);
        }
        printf("\n");
    }
    printf("transposed array:\n");
    for(int row = 0; row<3; row++){
        for(int column = 0; column<2; column++){
            printf("%d ", transposedArray[row][column]);
        }
        printf("\n");
    }
}