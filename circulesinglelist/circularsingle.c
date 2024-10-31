
#include <stdio.h>
#include <stdlib.h>
#include "circularsingle.h"
void CreateList(Linkedlist * lq)
{
    lq->head=NULL;
    lq->size=0;
}
int IsFull(Linkedlist * lq)
{
    return 0;
}
int IsEmpty(Linkedlist * lq)
{
    return lq->size==0;
}
void Insert(Linkedlist * lq ,LinkedType e , int pos)
{
    Node *temp=(Node *)malloc(sizeof(Node));
    temp->element=e;
    temp->next=NULL;
    if(pos==0)//first element
    {
        if(!lq->head)//& only element
        {
            lq->head=temp;
            temp->next=lq->head;
        }
        else//not only
        {
            Node* q = lq->head;
            while (q->next!=lq->head)
            q = q->next;
             temp->next=lq->head;
             q->next=temp;
             lq->head=temp;
        }
    }
    else {
        Node* q = lq->head;
        for (int i = 0; i < pos - 1; i++) {
            q = q->next;
        }
        if (pos == lq->size)
            temp->next = lq->head;
        else // Normal case insert between
            temp->next = q->next; // Link new node to the next node
        q->next = temp; // Link previous node to new node
    }
    lq->size++;
}
void Retrieve(Linkedlist * lq ,LinkedType *e , int pos )
{
    Node *q, *temp;

    if(pos==0)// at first
    {
        *e=lq->head->element;
        q=lq->head;
        if(lq->size==1)//only one element
            lq->head=NULL;
        else// not only must make last node pointer to the 2's node cuz first was deleted
        {
            Node *qq=lq->head;
            while(qq->next!=lq->head)
                qq=qq->next;
            qq->next=lq->head->next;
            lq->head=lq->head->next;
        }
      free(q);
    }
    else
    {
        q=lq->head;
        for(int i =0 ; i<pos-1 ; i++ , q=q->next);
            *e=q->next->element;
        temp=q->next;
        if(pos==lq->size-1)//make 1's node pointer to it and vise vesre
            q->next->next=lq->head;
        else
            q->next->next=q->next->next->next;
        free(temp);
    }
    lq->size--;
}

int Getindex(Linkedlist * lq  , int pos )
{
    if(pos>lq->size)
        return -1;
    Node *q, *temp;
    if(pos==0)
    {
        return lq->head->element;
    }
    else
    {
        q=lq->head ;
        for(int i =0 ; i<pos-1 ; i++ , q=q->next);
        return q->next->element;
    }
}
int ListSize(Linkedlist * lq)
{
    return lq->size;
}
void TraverseList(Linkedlist * lq , void (*pf)(LinkedType))
{
    Node *q=lq->head;
    int i=lq->size;
    while(i--)
    {
        (*pf)(q->element);
        q=q->next;
    }
}
void ClearList(Linkedlist * lq)
{
    Node *q=lq->head ;
    int i=lq->size;
    while(i--)
    {
        lq->head=q->next;
        free(q);
        q=lq->head;
    }
    lq->size=0;
}
