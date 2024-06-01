#include <iostream>
#include <string>
#include "function.h"

using namespace std;

List_stack::List_stack() : head(NULL), tail(NULL){
}

List_stack::~List_stack(){
    ListNode* curr = head;
    while (curr) {
        ListNode* temp = curr;
        curr = curr->nextPtr;
        delete temp;    
    }
}

void List_stack::push(const int &data){
    ListNode *newPtr = new ListNode(data);
    if(tail == NULL) head = tail = newPtr;
    else{
        head->prevPtr = newPtr;
        newPtr->nextPtr = head;
        head = newPtr;
    }
}

void List_stack::pop(){
    if(tail != NULL){
        if(head == tail){
            delete head;
            head = tail = NULL;
        }
        else{
            ListNode *curPtr = head;
            head = head->nextPtr;
            delete curPtr;
        }
    }
    else return;
}

void List_stack::print(){
    ListNode *currentPtr = head;
    while(currentPtr != NULL){
        cout << currentPtr->data;
        if(currentPtr->nextPtr != NULL) cout << " ";
        currentPtr = currentPtr->nextPtr; 
    }
}