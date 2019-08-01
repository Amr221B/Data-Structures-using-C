/*
 * list.h
 *
 * This library is an implementation of dynamic list of integers
 *
 *  	Created on: 30/7/2019
 *      Author: Amr Halim
 */
#ifndef LIST_H
#define LIST_H
typedef struct{
 //pointer to list array
 int *list;
 //total list size
 int size;
 //index of the last element in the list
 int end;
}listType;

void LIST_init(listType *ls, int size);
int LIST_insert(listType *ls, int val);
int LIST_insertAtIndex(listType *ls, int val, int index);
int LIST_remove(listType *ls, int index);
int LIST_get(listType *ls, int index);
int LIST_edit(listType *ls, int val, int index);
void LIST_print(listType *ls);
int LIST_count(listType *ls);
#endif // LIST_H

