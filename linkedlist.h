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
typedef struct node nodeType;

int LINKEDLIST_addNode(nodeType **head, int d);
int LINKEDLIST_addNodeAtBeginning(nodeType **head, int d);
int LINKEDLIST_addNodeAtIndex(nodeType **head, int d, int index);
int LINKEDLIST_removeNode(nodeType **head, int index);
void LINKEDLIST_print(nodeType **head);
int LINKEDLIST_reverse(nodeType **head);
int LINKEDLIST_getNoadeValue(nodeType **head, int index);
int LINKEDLIST_editNoadeValue(nodeType **head, int d, int index);
int LINKEDLIST_count(nodeType **head);
#endif // LINKED_LIST_H


