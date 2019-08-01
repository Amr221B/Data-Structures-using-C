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

int LINKEDLIST_addNode(nodeType **head, int d){
    int status=FAILED;
    nodeType *newNode;
    newNode=(nodeType *) malloc(sizeof(nodeType));
    newNode->data=d;
    newNode->next=(nodeType *) NULL;
    //first node (head)
    if(!(*head)){
        *head=newNode;
        status=SUCCESS;
    }
    else{
        nodeType *lastNode=*head;
        while(lastNode->next){
            lastNode=lastNode->next;
        }
        lastNode->next=newNode;
        status=SUCCESS;
    }
    return status;
}
int LINKEDLIST_addNodeAtBeginning(nodeType **head, int d){
    nodeType *newNode;
    newNode=(nodeType *) malloc(sizeof(nodeType));
    newNode->data=d;
    if(*head){
        newNode->next=*head;
    }
    else{
        newNode->next=(nodeType *) NULL;
    }
    *head=newNode;
    return SUCCESS;
}

int LINKEDLIST_addNodeAtIndex(nodeType **head, int d, int index){
    if(index>0){
        int i=1;
        nodeType *last, *prevLast;
        last=*head;
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
                newNode->next=*head;
                *head=newNode;
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


int LINKEDLIST_removeNode(nodeType **head, int index){
    if(*head&&index>0){
        int i=1;
        nodeType *last, *preLast;
        last=*head;
        while((last->next)&&(i<index)){
            preLast=last;
            last=last->next;
            i++;
        }
        if(i==index){
            if(index==1){
                *head=last->next;
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

void LINKEDLIST_print(nodeType **head){
    nodeType *temp=*head;
        while(temp){
        printf("%d ", temp->data);
        temp=temp->next;
    }
}

int LINKEDLIST_reverse(nodeType **head){
    if(*head){
        nodeType *currentNode, *prevNode, *nextNode;
        prevNode=*head;
        currentNode=prevNode->next;
        prevNode->next=(nodeType *) NULL;
        while(currentNode){
            nextNode=currentNode->next;
            currentNode->next=prevNode;
            prevNode=currentNode;
            currentNode=nextNode;
        }
        *head=prevNode;
        return SUCCESS;
    }
    return FAILED;
}

int LINKEDLIST_getNoadeValue(nodeType **head, int index){
    if(*head&&index>0){
        int i=1;
        nodeType *temp=*head;
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

int LINKEDLIST_editNoadeValue(nodeType **head, int val, int index){
    if(*head&&index>0){
        int i=1;
        nodeType *temp=*head;
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

int LINKEDLIST_count(nodeType **head){
    int i=0;
    nodeType *temp=*head;
    while(temp){
        temp=temp->next;
        i++;
    }
    return i;
}
