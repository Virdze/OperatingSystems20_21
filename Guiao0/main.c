#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "auxs.h"
#include "main.h"


void printArray(int *a,int size){
    for(int i = 0; i < size; i++)
        printf("%d",a[i]);
    printf("\n");
}

int main(){
    int *a,
        array2[5] = {1,2,3,4,5};
    fill(&a,5,6);
    printf("%d\n", find(array2,5,3));
    printArray(a,5);
    return 0;
}
