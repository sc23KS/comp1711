#include <stdio.h>

void reverseArray(int array[], int length){
    int start = 0;
    int end = length-1;
    while(start<end){
        int temp = array[start];
        array[start] = array[end];
        array[end] = temp;
        start++;
        end--;
    }
    for(int j=0; j<length; j++){
        printf("%i ",array[j]);
    }
}
int main(){
    int array[5]={1,2,3,4,5};
    reverseArray(array,5);
    printf("\n");
}