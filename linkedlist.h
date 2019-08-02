/*
 * linkedlist.h
 *
 * This library is an implementation of dynamic linkedlist of integers
 *
 *  	Created on: 31/7/2019
 *      Author: Amr Halim
 */
#ifndef LINKED_LIST_H
#define LINKED_LIST_H
struct node{
 //data in the current node
 int data;
 //pointer the next node
 struct node* next;
};
struct linkedList{
 //pointer start node of the list
 struct node* head;
};
typedef struct node nodeType;
typedef struct linkedList linkedListType;

void LINKEDLIST_createEmptyList(linkedListType *ls);
int LINKEDLIST_addNode(linkedListType *ls, int d);
int LINKEDLIST_addNodeAtBeginning(linkedListType *ls, int d);
int LINKEDLIST_addNodeAtIndex(linkedListType *ls, int d, int index);
int LINKEDLIST_removeNode(linkedListType *ls, int index);
int LINKEDLIST_deleteList(linkedListType *ls);
void LINKEDLIST_print(linkedListType *ls);
int LINKEDLIST_reverse(linkedListType *ls);
int LINKEDLIST_getNoadeValue(linkedListType *ls, int index);
int LINKEDLIST_editNoadeValue(linkedListType *ls, int d, int index);
int LINKEDLIST_count(linkedListType *ls);
#endif // LINKED_LIST_H
