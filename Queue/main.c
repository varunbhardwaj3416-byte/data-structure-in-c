#include <stdio.h>
#include <stdlib.h>
#include "circular_queue.h"

int main() {
    int data , found ; 
    circular_queue * q = createCircularQueue(1) ; 
    enQueue(q , 10) ; 
    enQueue(q , 11) ;
    enQueue(q , 12) ; 
    enQueue(q , 13) ;
    deQueue(q , &data , &found) ; 
    if(found) {
        printf("Dequeued data is %d\n" , data) ;  
    }
    printf("Size of Queue is %d\n" , size(q)) ; 
    printf("Capacity of Queue is %d\n" , capacity(q)) ; 
    // trying to display the queue 
    printf("Displaying Queue \n") ; 
    for (int i = 0 ; i < q -> size ; ++i) {
        printf("%d\n" , q -> queue[(q -> front + i) % q -> capacity]) ; 
    }
    freeQueue(q) ; 
    printf("Freed Queue\n") ; 

    return 0;
}