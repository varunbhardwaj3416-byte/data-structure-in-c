#include <stdio.h>
#include "stack_array.h"
#include "stack_ll.h"

void displayStackLl(stack_using_linked_list * sll) {
    if(!sll) {
        printf("Null address entered , Try again \n") ; 
        return ; 
    }
    if (sll -> top == NULL) {
        printf("Stack is empty\n") ; 
        return ; 
    }
    node * temp = sll -> top ; 
    printf("Stack is : \n") ; 
    while(temp){
        printf("%d\n" , temp -> data) ; 
        temp = temp -> next ; 
    }
} 
void displayStack(Stack * Stack){
    if (!Stack) return ; 
    int tempTop = Stack -> top ; 
    while(tempTop != -1) {
        printf("Index : %d | Value : %d\n" , tempTop , Stack -> stack [tempTop]) ; 
        tempTop -= 1 ;  
    }
}

int main(){
    // in main testing of all functions are being done
    int data , found ; 
    Stack * stack = createStack(10) ; 
    pushStack(stack , 10) ; 
    pushStack(stack , 11) ; 
    pushStack(stack , 12) ; 
    popStack(stack , &data , &found); 
    if(found) printf("Popped element is : %d\n" , data) ; 
    pushStack(stack , 13) ; 
    peekStack(stack , &data , &found) ;
    if (found) printf("At top Element is %d\n" , data) ;  
    int checkFull = isFullStack(stack) ; 
    if (checkFull){
        printf("Full\n") ; 
    }
    else {
        printf("Not full\n") ; 
    }
    int emptyCheck = isEmptyStack(stack) ; 
    if (emptyCheck) {
        printf("Stack is empty\n") ;
    }
    else {
        printf("Stack is not empty\n") ; 
    }
    printf("Before doubling capacity is : %d\n" , capacityStack(stack)) ; 
    doubleStack(stack) ; 
    printf("After doubling capacity is : %d\n" , capacityStack(stack)) ;
    displayStack(stack) ;  
    freeStack(stack) ;  
    // checking of stack using linked list 
    stack_using_linked_list * sll = createStackLl() ; 
    pushStackLl(sll , 1) ; 
    pushStackLl(sll , 2) ; 
    pushStackLl(sll , 3) ; 
    pushStackLl(sll , 4) ; 
    popStackLl(sll , &data , &found) ;
    if(found) printf("Popped data is %d\n" , data) ;  
    peekStackLl(sll , &data , &found) ; 
    if(found){
        printf("At top of stack data is %d\n" , data) ;
    }
    if(isEmptyStackLl(sll)){
        printf("Stack is empty\n") ; 
    }
    else {
        printf("Stack is not empty\n") ; 
    }
    displayStackLl(sll) ; 

    freeStackLl(sll) ; 

    return 0 ; 
    
}