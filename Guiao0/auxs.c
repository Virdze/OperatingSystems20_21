#include "auxs.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int length(int * v){
    int i = 0;
    while(v[i] != '\0')
        i++;
    return i;
}

void fill(int *a, int size, int value){
    int * temp = (int*) malloc(size * sizeof(int));
    for(int i = 0; i < size; i++) {
        temp[i] = value;
    }
    *a = temp;
}

int find(int* vector, int size, int value){
    int res = 0;
    for(int i = 0; i < size; i++){
        if(vector[i] == value)
            res = vector[i];
    }
    if (res!= -1)
        return res;
    else
        return -1;
}