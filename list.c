/*
 * list.c
 *  	Created on: 30/7/2019
 *  	Author: Amr Halim
 */
#include "list.h"
#include <stdlib.h>
#define MAX_SIZE 512
#define initializeList(ptr, s) ptr=(int *)malloc(sizeof(int)*s)

typedef struct{
 int *list;
 int size;
 int end;
}ListType;

static ListType ls={0, MAX_SIZE, -1};

static void extendListSize(void){
    int i, *newList;
    //allocate a new space for list > 2*previous size
    initializeList(newList, 2*ls.size);
    //copy elements to the new list
    for(i=0; i<ls.size; i++){
        newList[i]=ls.list[i];
    }
    //remove the space allocated for the old list
    free(ls.list);
    ls.list=newList;
}

void LIST_insert(int val){
    //first creation of the list
    if(!(ls.list)){
        initializeList(ls.list, MAX_SIZE);
    }
    ls.end++;
    //if no empty space in list
    if(ls.end==ls.size){
        extendListSize();
    }
    ls.list[ls.end]=val;
}

void LIST_insertAtIndex(int val, int index){
    int i;
    //first creation of the list
    if(!(ls.list)){
        initializeList(ls.list, MAX_SIZE);
    }
    index--;
    ls.end++;
    //if no empty space in list
    if(ls.end==ls.size){
        extendListSize();
    }
    for(i=ls.end; i!=index; i--){
        ls.list[i]=ls.list[i-1];
    }
    ls.list[index]=val;
}

void LIST_remove(int index){
    int i;
    if((index-1)<=ls.end){
        for(i=index-1; i!=ls.end; i++){
            ls.list[i]=ls.list[i+1];
        }
        ls.end--;
    }
}

int LIST_get(int index){
    if((index-1)<=ls.end){
        return ls.list[index-1];
    }
    return -1;
}

void LIST_edit(int val, int index){
    if((index-1)<=ls.end){
        ls.list[index-1]=val;
    }
}

int LIST_count(void){
    return (ls.end+1);
}
