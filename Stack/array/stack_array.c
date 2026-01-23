#include <stdio.h>
#include <stdlib.h>
#include "stack_array.h"
// functions for normal stack 

struct Stack * createStack(int capacity){
    Stack * new = (Stack *) malloc(sizeof(Stack)) ; 
    if(!new) {
        return NULL ; 
    }
    new -> stack = (int*) malloc(sizeof(int) * capacity) ; 
    if (!new -> stack) {
        free(new) ; 
        return NULL ; 
    }
    new -> top = -1 ; 
    new -> capacity = capacity ; 
    return new ; 
}
int doubleStack(Stack * Stack){ // by amortized analysis if we do doubling instead of incrementing 
    // the amortized cost of push becomes O(1)
    if (!Stack) return 0 ; 
    int * new = realloc(Stack -> stack , sizeof(int) * Stack -> capacity * 2) ; 
    if (!new) {
        // failed to allocate memory , but didn't lost memory due to this 
        return 0 ; 
    }
    Stack -> stack = new ; 
    Stack -> capacity = Stack -> capacity * 2 ; 
    return 1 ; 
}
void pushStack(Stack * Stack , int data){
    if(!Stack) return ; 
    if (Stack -> top + 1 == Stack -> capacity){
        if(!doubleStack(Stack)) {
            return ; 
        }
    }
    Stack -> stack [++Stack -> top] = data ; 
}
void popStack(struct Stack * Stack , int * data , int * found ){
    if (Stack -> top == -1) {
        *found = 0 ; 
        return ;
    } // doesn't want to return some value when stack is empty so used *found 
    *found = 1 ; 
    *data = Stack -> stack[Stack -> top--] ; 
}
int isFullStack(Stack * Stack){
    if (Stack -> top + 1 == Stack -> capacity) return 1 ; 
    return 0 ; 
}
int isEmptyStack(Stack * Stack){
    if (Stack -> top == -1) return 1 ; 
    return 0 ; 
}
void peekStack (Stack * Stack , int * data , int * found){
     if (Stack -> top == -1) {
        *found = 0 ; 
        return ;
    }
    *found = 1 ; 
    *data = Stack -> stack[Stack -> top] ; 
}


void freeStack(Stack * Stack){
    if (!Stack) return ; 
    free(Stack -> stack) ; 
    free(Stack) ; 
}
int capacityStack(Stack * Stack) {
    return Stack -> capacity ; 
}
// function for stack using linked list 

