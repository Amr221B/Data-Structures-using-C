/*
 * linkedlist.c
 *  	Created on: 31/7/2019
 *  	Author: Amr Halim
 */
#include "linkedlist.h"
#include <stdlib.h>
#include <stdio.h>
#define FAILED  -1
#define SUCCESS 0

void LINKEDLIST_createEmptyList(linkedListType *ls){
    if(ls){
        ls->head = (nodeType *) NULL;
    }
}

int LINKEDLIST_addNode(linkedListType *ls, int d){
    int status=FAILED;
    nodeType *newNode;
    newNode=(nodeType *) malloc(sizeof(nodeType));
    newNode->data=d;
    newNode->next=(nodeType *) NULL;
    //first node (head)
    if(!(ls->head)){
        ls->head=newNode;
        status=SUCCESS;
    }
    else{
        nodeType *lastNode=ls->head;
        while(lastNode->next){
            lastNode=lastNode->next;
        }
        lastNode->next=newNode;
        status=SUCCESS;
    }
    return status;
}
int LINKEDLIST_addNodeAtBeginning(linkedListType *ls, int d){
    nodeType *newNode;
    newNode=(nodeType *) malloc(sizeof(nodeType));
    newNode->data=d;
    if(ls->head){
        newNode->next=ls->head;
    }
    else{
        newNode->next=(nodeType *) NULL;
    }
    ls->head=newNode;
    return SUCCESS;
}

int LINKEDLIST_addNodeAtIndex(linkedListType *ls, int d, int index){
    if(ls->head&&index>0){
        int i=1;
        nodeType *last, *prevLast;
        last=ls->head;
        while((last)&&(i<index)){
            prevLast=last;
            last=last->next;
            i++;
        }
        if(i==index){
            nodeType *newNode;
            newNode=(nodeType *) malloc(sizeof(nodeType));
            newNode->data=d;
            newNode->next=(nodeType *) NULL;
            if(index==1){
                newNode->next=ls->head;
                ls->head=newNode;
            }
            else{
                newNode->next=last;
                prevLast->next=newNode;
            }
            return SUCCESS;
        }
    }
    return FAILED;
}


int LINKEDLIST_removeNode(linkedListType *ls, int index){
    if(ls->head&&index>0){
        int i=1;
        nodeType *last, *preLast;
        last=ls->head;
        while((last->next)&&(i<index)){
            preLast=last;
            last=last->next;
            i++;
        }
        if(i==index){
            if(index==1){
                ls->head=last->next;
            }
            else{
                preLast->next=last->next;
            }
            free(last);
            return SUCCESS;
        }
    }
    return FAILED;
}

int LINKEDLIST_deleteList(linkedListType *ls){
    nodeType *iterator, *temp;
    iterator=ls->head;
    while(iterator){
        temp=iterator;
        iterator=iterator->next;
        free(temp);
    }
    ls->head = (nodeType *) NULL;
    return SUCCESS;
}

void LINKEDLIST_print(linkedListType *ls){
    nodeType *temp=ls->head;
        while(temp){
        printf("%d ", temp->data);
        temp=temp->next;
    }
}

int LINKEDLIST_reverse(linkedListType *ls){
    if(ls->head){
        nodeType *currentNode, *prevNode, *nextNode;
        prevNode=ls->head;
        currentNode=prevNode->next;
        prevNode->next=(nodeType *) NULL;
        while(currentNode){
            nextNode=currentNode->next;
            currentNode->next=prevNode;
            prevNode=currentNode;
            currentNode=nextNode;
        }
        ls->head=prevNode;
        return SUCCESS;
    }
    return FAILED;
}

int LINKEDLIST_getNoadeValue(linkedListType *ls, int index){
    if(ls->head&&index>0){
        int i=1;
        nodeType *temp=ls->head;
        while((temp->next)&&(i<index)){
            temp=temp->next;
            i++;
        }
        if(i==index){
            return temp->data;
        }
    }
    return FAILED;
}

int LINKEDLIST_editNoadeValue(linkedListType *ls, int val, int index){
    if(ls->head&&index>0){
        int i=1;
        nodeType *temp=ls->head;
        while((temp->next)&&(i<index)){
            temp=temp->next;
            i++;
        }
        if(i==index){
            temp->data=val;
            return SUCCESS;
        }
    }
    return FAILED;
}

int LINKEDLIST_count(linkedListType *ls){
    int i=0;
    nodeType *temp=ls->head;
    while(temp){
        temp=temp->next;
        i++;
    }
    return i;
}
