﻿#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

/* Implementera interface från queue.h här */
QueuePtr new_queue()
{
    QueuePtr qPtr = (QueuePtr) malloc(sizeof(struct QueueElement));
    qPtr->prio = MAX_PRIO;
    qPtr->next = 0;
    return qPtr;
}

 // tar bort kön helt och hållet
void delete_queue(QueuePtr q)
{
            clear(q);
            free(q);
}

// tar bort köelementen men behåller kön
void clear(QueuePtr q)
{
    QueuePtr temp= q->next;
    while(temp)
    {
                QueuePtr nextElement = temp->next;
                //free(temp->data);
                free(temp);
                temp = nextElement;
    }
    //behövs detta?
    q->next = 0;
    
}


// räknar köns aktuella längd
int size(QueuePtr q)
{
    int size = 0;
    QueuePtr temp = q;
    while(temp->next){
        size = size + 1;
        temp = temp->next;
    }
    
    return size; 
}

QueuePtr createQueueElement(QueuePtr q, int prio, DataPtr d)
{
    QueuePtr qPtr = (QueuePtr) malloc(sizeof(struct QueueElement));
    //malloc data?
    qPtr->prio = prio;
    qPtr->data = d;
    qPtr->next = 0;
    q->next = qPtr;
    return qPtr;
}

// lägger in d på rätt plats 
void add(QueuePtr q, int prio, DataPtr d)
{
        //Kollar om size är 1 för annars antar vi att det finns ett nästa element så hanterar detta fall.
        if(!q->next)
        {
            createQueueElement(q, prio, d);
            return;
        }
        //Skapa temp variabel
        QueuePtr temp = q;
        //While tills rätt plats
        while(temp->next)
        {
            if(temp->next->prio>=prio)
            {
                temp = temp->next;
            }
            else
            {
                break;
            }
        }
        //Hämtar det som finns framåt i kön
        QueuePtr nextTemp = temp->next;
        
        //Skapar köelement på rätt plats, pekar bakåt
        QueuePtr newPtr = createQueueElement(temp, prio, d);
        
        //Sätter rätt pekare frammåt i kön
        newPtr->next = nextTemp;
}



// avläser första dataelementet 
DataPtr get_first(QueuePtr q)
{
    return q->next->data;   
}

// tar bort första köelementet
void remove_first(QueuePtr q)
{
				QueuePtr firstElement = q->next;
                if(firstElement){
                        QueuePtr newStart  = firstElement->next;
                        //free(firstElement->data);
                        free(firstElement);
                        q->next = newStart;
                }
                
}