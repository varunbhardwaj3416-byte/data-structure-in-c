#include <stdio.h>
#include <stdlib.h>
#include "vectors.h"

Vector * createVector(int capacity) {
    Vector * new = (Vector*) malloc(sizeof(Vector)) ; 
    if (!new) return NULL ; 
    new -> data = (int*) malloc(sizeof(int) * capacity) ; 
    if(!new -> data) return NULL ; 
    new -> capacity = capacity ; 
    new -> size = 0 ; 
    return new ; 
}

void shrink(Vector * vector) {
    if (!vector) return ; 
    int * new = realloc(vector -> data , vector -> capacity / 2) ; 
    if (!new) {
        printf("Shrinking failed\n") ;
        return ;  
        // else shrinking succeed
    }
    printf("Vector shrinked\n") ; 
}

void popBack(Vector * vector , int * found , int * data) {
    if (!vector || !found || !data) {
        *found = 0 ; 
        return ; 
    }
    *found = 1 ; 
    *data = vector -> data[vector -> size - 1] ; 
    vector -> size -= 1 ; 
    if (vector -> size < vector -> capacity / 4) {
        // shrink the vector to half 
        shrink(vector) ; 
    }
}
void pushBack(Vector * vector , int data) {
    if (!vector) return ; 
    vector -> data [vector -> size] = data ; 
    vector -> size += 1 ; 
}
int get(Vector * vector ,int index , int * data) {  // function would return 1 if value found else 0 , if 1 then we check at data
    if (!vector || !data) return 0; 
    if (index < vector -> size){
        *data = vector -> data [index] ; 
        return 1 ; 
    }
    return 0 ; 
}
int set (Vector * vector , int index , int value) {
    if (!vector) return 0 ; 
    if (index < vector -> size) {
        vector -> data[index] = value ; 
        return 1 ; 
    }
    return 0 ; 
} 
int capacity(Vector * vector) {
    if (!vector) return 0 ; 
    return vector -> capacity ; 
}
int size(Vector * vector) {
    if (!vector) return 0 ; 
    return vector -> size ; 
}
void doubleVector(Vector * vector) {
    if (!vector) return ;
    int * new = realloc(vector -> data , vector -> capacity * 2) ; 
    if (!new) {
        printf("Doubling of Vector failed . Heap is full , Try again .\n") ;  
        return ; 
    }
    printf("Vector Doubled\n") ; 
  
}
void freeVector(Vector * vector) {
    if(!vector) return ; 
    free(vector -> data) ; 
    free(vector) ;
    printf("Vector Freed\n") ; 
}
void display(Vector * vector) {
    if (!vector) return  ; 
    for (int i = 0 ; i < vector -> size ; ++i) {
        printf("%d\t" , vector -> data[i]) ; 
    }
    printf("\n") ; 

}
