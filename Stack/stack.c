#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct Stack * createStack(int capacity){
    Stack * new = (Stack *) malloc(sizeof(Stack)) ; 
    if(!new) {
        return NULL ; 
    }
    new -> stack = (int*) malloc(sizeof(int) * capacity) ; 
    if (!new -> stack) {
        return NULL ; 
    }
    new -> top = -1 ; 
    new -> capacity = capacity ; 
    return new ; 
}
void doubleStack(Stack * Stack){ // by amortized analysis if we do doubling instead of incrementing
                                        // the amortized cost of push becomes O(1)
    if (!Stack) return ; 
    int * new = realloc(Stack -> stack , Stack -> capacity * 2) ; 
    if (!new) {
        // failed to allocate memory , but didn't lost memory due to this 
        return ; 
    }
    Stack -> stack = new ; 
    Stack -> capacity = Stack -> capacity * 2 ; 
}
void push(Stack * Stack , int data){
    if(!Stack) return ; 
    if (Stack -> top + 1 == Stack -> capacity) doubleStack(Stack) ; 
    Stack -> stack [++Stack -> top] = data ; 
}
void pop(struct Stack * Stack , int * data , int * found ){
    if (Stack -> top == -1) {
        *found = 0 ; 
        return ;
    } // doesn't want to return some value when stack is empty so used *found 
    *found = 1 ; 
    *data = Stack -> stack[Stack -> top--] ; 
}
int isFull(Stack * Stack){
    if (Stack -> top + 1 == Stack -> capacity) return 1 ; 
    return 0 ; 
}
int isEmpty(Stack * Stack){
    if (Stack -> top == -1) return 1 ; 
    return 0 ; 
}
void peek (Stack * Stack , int * data , int * found){
     if (Stack -> top == -1) {
        *found = 0 ; 
        return ;
    }
    *found = 1 ; 
    *data = Stack -> stack[Stack -> top] ; 
}

void displayStack(Stack * Stack){
    if (!Stack) return ; 
    int tempTop = Stack -> top ; 
    while(tempTop != -1) {
        printf("Index : %d | Value : %d\n" , tempTop , Stack -> stack [tempTop]) ; 
        tempTop -= 1 ;  
    }
}
void freeStack(Stack * Stack){
    if (!Stack) return ; 
    free(Stack -> stack) ; 
    free(Stack) ; 
    printf("Memory Freed\n") ; 
}
int capacity(Stack * Stack) {
    return Stack -> capacity ; 
}