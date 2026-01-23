#ifndef STACK_H
#define STACK_H

typedef struct Stack { // stack implemented using normal approach 
    int * stack ; 
    int capacity ; 
    int top ; 
} Stack; 

Stack * createStack(int) ; 
void pushStack(Stack * , int) ; 
void popStack(Stack * , int * , int *) ; 
void peekStack(Stack * , int * , int *) ; 
int isEmptyStack(Stack *) ; 
int isFullStack(Stack *) ;  
void freeStack(Stack *) ; 
int doubleStack(Stack *) ; 
int capacityStack(Stack *) ;
#endif