#ifndef STACK_LL
#define STACK_LL

typedef struct node {
    int data ; 
    struct node * next ; 
} node ; 

typedef struct stack_using_linked_list{
    node * top ; // point to topmost node 
} stack_using_linked_list ; 

node * createNode(int) ; // int refers to the data 
stack_using_linked_list * createStackLl() ; 
void freeStackLl(stack_using_linked_list *) ; 
void pushStackLl(stack_using_linked_list * , int) ; 
void popStackLl(stack_using_linked_list * , int * , int * ) ;  
void peekStackLl(stack_using_linked_list * , int * , int *) ; 
int isEmptyStackLl(stack_using_linked_list * ) ; 

#endif


