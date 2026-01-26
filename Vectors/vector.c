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
        return ;  
        // else shrinking succeed
    }
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
void get(Vector * vector ,int index , int * data , int * found) {  // *found = 1 if index is valid else 0
    if (!vector || !data) return ; 
    if (index < vector -> size){
        *data = vector -> data [index] ; 
        return  ; 
    }
    return  ; 
}
void set (Vector * vector , int index , int value , int * status) {
    if (!vector) return  ;                     // value of status would be 1 if index sent was valid 
    if (index < vector -> size) {
        vector -> data[index] = value ; 
        return  ; 
    }
    return  ; 
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
        return ; 
    }
  
}
void freeVector(Vector * vector) {
    if(!vector) return ; 
    free(vector -> data) ; 
    free(vector) ;
}

