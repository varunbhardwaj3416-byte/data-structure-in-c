#include <stdio.h>
#include "stack.h"

int main(){
    // in main testing of all functions are being done
    int data , found ; 
    Stack * stack = createStack(10) ; 
    push(stack , 10) ; 
    push(stack , 11) ; 
    push(stack , 12) ; 
    pop(stack , &data , &found); 
    if(found) printf("Popped element is : %d\n" , data) ; 
    push(stack , 13) ; 
    peek(stack , &data , &found) ;
    if (found) printf("At top Element is %d\n" , data) ;  
    displayStack(stack) ;
    int checkFull = isFull(stack) ; 
    if (checkFull){
        printf("Full\n") ; 
    }
    else {
        printf("Not full\n") ; 
    }
    int emptyCheck = isEmpty(stack) ; 
    if (emptyCheck) {
        printf("Stack is empty\n") ;
    }
    else {
        printf("Stack is not empty\n") ; 
    }
    printf("Before doubling capacity is : %d\n" , capacity(stack)) ; 
    doubleStack(stack) ; 
    printf("After doubling capacity is : %d\n" , capacity(stack)) ; 
    freeStack(stack) ;  
    return 0 ; 
    
}