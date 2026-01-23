#include <stdio.h>
#include "vectors.h"

int main() {
    int found , data ; 
    Vector * v = createVector(1) ; 
    pushBack(v , 10) ; 
    pushBack(v , 11) ; 
    pushBack(v , 12) ; 
    popBack(v , &found , &data) ; 
    if(found) {
        printf("Popped data is %d\n" , data) ; 
    }
    set(v , 0 , 300) ; 
    if (get(v , 1 , &data)) {
        printf("Get working | Index : 1 | Value : %d\n" , data) ; 
    }
    doubleVector(v) ; 
    display(v) ; 
    printf("Size of a vector is : %d\n" , size(v)) ; 
    printf("Capacity of a vector is %d\n" , capacity(v)) ; 
    freeVector(v) ; 


    return 0;
}