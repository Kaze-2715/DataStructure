#include "linkedQueue.h"
#include <stdio.h>
#include <stdlib.h>

int enqueue(item *data, queue *Queue)
{
    if (Queue->size == Queue->MAXSIZE)
    {
        puts("Queue is full");
        return 0;
    }
    
    node *new = malloc(sizeof(node));
    if (Queue->front == NULL)
    {
        Queue->front = new;
    }
    new->data = *data;
    new->next = Queue->rear;
    new->prev = NULL;
    Queue->rear = new;
    
    Queue->size++;
    return 1;
}

int dequeue(item *data, queue *Queue)
{
    if (Queue->size == 0)
    {
        puts("Queue is empty");
        return 0;
    }
    node *toDelete = Queue->front;
    if (Queue->front == Queue->rear)
    {
        Queue->front = NULL;
        Queue->rear = NULL;
    }
    else
    {
        Queue->front = toDelete->prev;
        Queue->front->next = NULL;
    }
    *data = toDelete->data;
    free(toDelete);
    return 1;
}

int get(item *data, queue *Queue)
{
    if (Queue->front == NULL)
    {
        puts("Queue is empty");
        return 0;
    }
    *data = Queue->front->data;
    return 1;
}

int clear(queue *Queue)
{
    if (Queue->rear == NULL)
    {
        puts("Queue is empty");
        return 0;
    }
    node *cur = Queue->rear;
    while (cur != NULL)
    {
        node *next = cur->next;
        free(cur);
        cur = next;
    }
    Queue->size = 0;
}

int destroy(queue *Queue)
{
    if (Queue->front == NULL)
    {
        Queue->rear = NULL;
        Queue->size = 0;
        return 1;
    }
    node *cur = Queue->rear;
    while (cur != NULL)
    {
        node *next = cur->next;
        free(cur);
        cur = cur->next;
    }
    Queue->size = 0;
    return 1;
}

int isEmpty(queue *Queue)
{
    return (Queue->size == 0) ? 1 : 0;
}

int isFull(queue * Queue)
{
    return (Queue->size == Queue->MAXSIZE) ? 1 : 0;
}

void initQueue(queue *Queue, int maxSize)
{
    Queue->MAXSIZE = maxSize;
    Queue->size = 0;
    Queue->front = NULL;
    Queue->rear = NULL;
    Queue->enqueue = enqueue;
    Queue->dequeue = dequeue;
    Queue->get = get;
    Queue->clear = clear;
    Queue->destroy = destroy;
    Queue->isEmpty = isEmpty;
    Queue->isFull = isFull;
}

item getItem()
{
    item data;
    printf("Enter an item: ");
    scanf("%d", &data);
    return data;
}
