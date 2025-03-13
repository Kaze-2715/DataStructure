#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "staticQueue.h"

int initQueue(queue *Queue, int size)
{
    Queue->space = (item *)malloc(sizeof(item) * size);
    if (Queue->space == NULL)
    {
        return 0; // 分配失败返回0
    }

    Queue->front = 0;
    Queue->rear = 0;
    Queue->size = size;

    // 初始化函数指针
    Queue->enqueue = enqueue;
    Queue->dequeue = dequeue;
    Queue->get = get;
    Queue->isFull = isFull;
    Queue->isEmpty = isEmpty;
    Queue->clear = clear;
    Queue->destroy = destroy;

    return 1; // 初始化成功返回1
}

int destroy(queue *Queue)
{
    if (Queue->space == NULL)
    {
        return 0;
    }
    free(Queue->space);
    Queue->front = 0;
    Queue->rear = 0;
    return 1;
}

int enqueue(item *data, queue *Queue)
{
    if (Queue->rear + 1 == Queue->front)
    {
        puts("Queue is full");
        return 0;
    }
    Queue->rear = (Queue->rear + 1) / Queue->size;
    Queue->space[Queue->rear] = *data;
    return 1;
}

int dequeue(item *data, queue *Queue)
{
    if (Queue->rear == Queue->front)
    {
        puts("Queue is empty");
        return 0;
    }
    *data = Queue->space[Queue->front];
    Queue->front = (Queue->front + 1) / Queue->size;

    return 1;
}

int get(item *data, queue *Queue)
{
    if (Queue->rear == Queue->front)
    {
        puts("Queue is empty");
        return 0;
    }
    *data = Queue->space[Queue->front];
    return 1;
}

int isFull(queue *Queue)
{
    return (Queue->rear + 1 == Queue->front) ? 1 : 0;
}

int isEmpty(queue *Queue)
{
    return (Queue->front == Queue->rear) ? 1 : 0;
}

int clear(queue *Queue)
{
    memset(Queue->space, 0, Queue->size * sizeof(item));
    Queue->front = 0;
    Queue->rear = 0;
    return 1;
}

item getItem()
{
    item temp;
    printf("请输入一个整数: ");
    scanf("%d", &temp);
    return temp;
}
