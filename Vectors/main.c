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
   get(v , 1 , &data , &found) ; 
   if(found) {
    printf("Index : 1 | Value : %d\n" , data) ; 
   }
   set(v , 1 , 200 , &found) ; 
   if(found) {
    printf("Updated Value\nIndex : 1 | Value : 200\n") ; 
   }
    doubleVector(v) ; 
    printf("Size of a vector is : %d\n" , size(v)) ; 
    printf("Capacity of a vector is %d\n" , capacity(v)) ; 
    freeVector(v) ; 


    return 0;
}