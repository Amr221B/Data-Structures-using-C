/*
 * list.h
 *
 * This library is an implementation of dynamic list
 *
 *  	Created on: 30/7/2019
 *      Author: Amr Halim
 */
#ifndef LIST_H
#define LIST_H
void LIST_insert(int val);
void LIST_insertAtIndex(int val, int index);
void LIST_remove(int index);
int LIST_get(int index);
void LIST_edit(int val, int index);
int LIST_count(void);
#endif // LIST_H

