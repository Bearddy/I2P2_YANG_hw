#include <stdio.h>
#include <stdlib.h>
#include "function.h"

void eFormSort(Node* head){
    Node* curr = head;
    Node* main = head;
    Node* prev;
    
    int len = 0;
    while(curr->next != NULL){
        len++;
        curr = curr->next;
    }

    for(int i = 2; i <= len; i++){
        curr = main->next;
        prev = main;

        while (curr->serial != i) {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;
        curr->next = main->next;
        main->next = curr;

        main = main->next;
    }
    

}
