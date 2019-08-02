/*
 * list.c
 *  	Created on: 30/7/2019
 *  	Author: Amr Halim
 */
#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#define FAILED  -1
#define SUCCESS 0

static void listResize(listType *ls, int size){
    int i, *newList;
    //allocate a new space for list > 2*previous size
    newList = (int *)malloc(sizeof(int)*size);
    //copy elements to the new list
    for(i=0; i<ls->size; i++){
        newList[i]=ls->list[i];
    }
    //remove the space allocated for the old list
    free(ls->list);
    ls->list=newList;
}

void LIST_init(listType *ls, int size){
    if(ls){
        ls->size = size;
        ls->end = -1;
        ls->list = (int *) malloc(sizeof(int)*size);
    }
}

int LIST_insert(listType *ls, int val){
    if(ls&&ls->list){
        ls->end++;
        //if no empty space in list
        if(ls->end==ls->size){
            listResize(ls, ls->size*2);
        }
        ls->list[ls->end]=val;
        return SUCCESS;
    }
    return FAILED;
}

int LIST_insertAtIndex(listType *ls, int val, int index){
    int i;
    if(ls&&ls->list){
        index--;
        if((index>=0)&&(index<=ls->end)){
            ls->end++;
            //if no empty space in list
            if(ls->end==ls->size){
                listResize(ls, ls->size*2);
            }
            for(i=ls->end; i!=index; i--){
                ls->list[i]=ls->list[i-1];
            }
            ls->list[index]=val;
            return SUCCESS;
        }
    }
    return FAILED;
}

int LIST_remove(listType *ls, int index){
    int i;
    if(ls&&ls->list){
        index--;
        if((index>=0)&&(index<=ls->end)){
            for(i=index; i!=ls->end; i++){
                ls->list[i]=ls->list[i+1];
            }
            ls->list[i]=0;
            ls->end--;
            return SUCCESS;
        }
    }
    return FAILED;
}

int LIST_deleteList(listType *ls){
    free(ls->list);
    ls->size=0;
    ls->end=-1;
    return SUCCESS;
}

int LIST_get(listType *ls, int index){
    if(ls&&ls->list){
        index--;
        if((index>=0)&&(index<=ls->end)){
        return ls->list[index];
        }
    }
    return FAILED;
}

int LIST_edit(listType *ls, int val, int index){
    if(ls&&ls->list){
        index--;
        if((index>=0)&&(index<=ls->end)){
            ls->list[index]=val;
            return SUCCESS;
        }
    }
    return FAILED;
}
void LIST_print(listType *ls){
    if(ls&&ls->list){
        for(int i=0; i<(ls->end+1); i++){
            printf("%d ", ls->list[i]);
        }
    }
}

int LIST_count(listType *ls){
    if(ls&&ls->list){
        return (ls->end+1);
    }
    return FAILED;
}
