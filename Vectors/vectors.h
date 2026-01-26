#ifndef VECTOR_H
#define VECTOR_H

typedef struct Vector {
    int * data ; 
    int size ; 
    int capacity ; 

} Vector ; 
Vector * createVector(int) ; // for capacity 
void popBack(Vector * , int * , int *) ;  // 2 integer pointer . one for if vector is empty then found = 0 else found = 1
void pushBack(Vector * , int )  ; 
void get(Vector * , int , int * , int *) ; 
void set (Vector * , int , int , int *) ;// first int for index , second one for value 
int size (Vector *) ;
int capacity (Vector *) ; 
void doubleVector(Vector *) ; 
void shrink(Vector *) ; 
void freeVector(Vector * ) ;


#endif 