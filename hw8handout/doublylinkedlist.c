/* Yanling Wang Fall 2018 */
#include <stdio.h>
#include <stdlib.h>
#include "doublylinkedlist.h"

void insertHead(doublyLinkedList *listPtr, int value) {
  //create new head node
  listNode *newHead = (listNode *)malloc(sizeof(listNode));
  newHead ->value = value;
  newHead -> prev = NULL;
  
  //if list is empty, insert new head node
  if((listPtr->tail == NULL) && (listPtr->head == NULL)){
    newHead->next = NULL;
    listPtr->head = newHead;
    listPtr->tail = newHead;
    return;
 }

  //replace current head with new head node
  else{
    newHead->next =listPtr->head;
    listPtr->head->prev = newHead;
    listPtr->head = newHead;
    return;  
  }
}

int removeTail(doublyLinkedList *listPtr) {
  //check if list is empty in memory. If it's not then call to function returns 0
  if((listPtr->tail == NULL) && (listPtr->head ==NULL)){
    return 0;
  }
  //while list has more than one node free tail and assign newtail
  else if(listPtr->tail->prev != NULL){
    listNode *newTail = listPtr -> tail->prev;
    newTail -> next = NULL;
    int val = listPtr->tail->value;
    free(listPtr->tail);
    listPtr->tail = newTail;
    return val;  
  }
  //if list only has one node reset list
  else{
    listNode *Tail = listPtr->tail;
    int val = Tail->value;
    free(Tail);
    listPtr->tail = NULL;
    listPtr->head = NULL;
    return val;
  }
} 

void showHead(doublyLinkedList *listPtr) {
  listNode *head = listPtr->head;
  printf("list head: ");
  while (head != NULL) {
    printf("%d ", head->value);
    head = head->next;
  } 
  printf("nil\n");
  return;
} 
void showTail(doublyLinkedList *listPtr) {
  listNode *tail = listPtr->tail;
  printf("list tail: ");
  while (tail != NULL) {
    printf("%d ", tail->value);
    tail = tail->prev;
  } 
  printf("nil\n");
  return;
} 
void freeList(doublyLinkedList *listPtr) { 
  listNode *head = listPtr->head;
  listNode *temp;
  while(head != NULL) {
    temp = head->next;
    free(head);
    head = temp;
  }
  listPtr->head = NULL;
  listPtr->tail = NULL;
  return;
}

