/* Yanling Wang Fall 2018 */
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/* print out the content of a list */
void displayList(listNode *list) {
  printf("list: ");
  while(list != NULL) {
    printf("%d ", list->value);
    list = list->next;
  }
  printf("%p\n", list);
  return;
}

/* given a pointer to the head of the list and a value,
 * add a new node with value to the head of the list */
void push(listNode **listPtr, int value) {
  listNode *newNodePtr = (listNode *)malloc(sizeof(listNode));
  newNodePtr->value = value;
  newNodePtr->next = *listPtr;
  *listPtr = newNodePtr;
  return;
}
/* remove the head of the list (and free its memory), and
 * return its value. If the list is empty, return 0 */ 
int pop(listNode **listPtr) {
  int value = 0;
  listNode *tempPtr;
  if (*listPtr) {
    tempPtr = *listPtr;
    value = tempPtr->value;
    *listPtr = tempPtr->next;
    free(tempPtr);
  }
  return value;
}

/* remove and free memory of all the element of the list. */
void destroyList(listNode **listPtr) {
  listNode *temp = *listPtr;
  while(temp != NULL) {
    *listPtr = (*listPtr) -> next;
    free(temp);
    temp = *listPtr;
  }
  return;
}

void reverse(listNode **listPtr) {
  listNode *prePtr = NULL;
  listNode *currPtr, *nextPtr;
  currPtr = *listPtr;
  while(currPtr != NULL){
    nextPtr = currPtr-> next;
    currPtr->next = prePtr;
    prePtr = currPtr;
    currPtr = nextPtr;
  }
  *listPtr = prePtr;  
  return;    
}

void insert(listNode **listPtr, int value) {
  listNode *newNodePtr = (listNode *)malloc(sizeof(listNode));
  newNodePtr -> value = value;
  newNodePtr -> next = NULL;
  
  if (*listPtr == NULL){
   *listPtr = newNodePtr;
  }
  else {
   listNode *tempPtr  = *listPtr;
   while (tempPtr->next != NULL){
    tempPtr = tempPtr->next;
   }
   tempPtr->next =newNodePtr;
  }  
return; 
}


void removeAll(listNode **listPtr, int value){
  listNode *temp = *listPtr;
  listNode *prePtr;
  while(temp != NULL){
    if(temp->value == value){
      *listPtr = (*listPtr)->next;
      free(temp);
      temp = *listPtr;
    }
    else{
      break;
    }
  } 
  while(temp != NULL){
    while(temp!=NULL && temp->value!=value){
      prePtr = temp;
      temp = prePtr->next;
    }
    if(temp != NULL){
      prePtr->next = temp->next;

      free(temp);
      temp = prePtr->next;
    }
    else {return;}
  }
    
}

int count(listNode *listPtr, int value) {
 int counter = 0; 
  while(listPtr != NULL){
   if(listPtr -> value == value){
     counter++;
   }
   listPtr = listPtr->next;
  }

 return counter;
} 
