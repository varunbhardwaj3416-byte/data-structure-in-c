#ifndef STACK_H
#define STACK_H

typedef struct Stack {
    int * stack ; 
    int capacity ; 
    int top ; 
} Stack; 

Stack * createStack(int) ; 
void push(Stack * , int) ; 
void pop(Stack * , int * , int *) ; 
void peek(Stack * , int * , int *) ; 
int isEmpty(Stack *) ; 
int isFull(Stack *) ;  
void freeStack(Stack *) ; 
void doubleStack(Stack *) ; 
void displayStack(Stack *) ; 
int capacity(Stack *) ;

#endif

