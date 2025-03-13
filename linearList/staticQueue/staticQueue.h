#ifndef STATIC_QUEUE_H
#define STATIC_QUEUE_H

typedef int item;
typedef struct queue queue;

struct queue
{
    item *space;
    int front;
    int rear;
    int size;

    int (*enqueue)(item *data, queue *Queue);
    int (*dequeue)(item *data, queue *Queue);
    int (*get)(item *data, queue *Queue);
    int (*isFull)(queue *Queue);
    int (*isEmpty)(queue *Queue);
    int (*clear)(queue *Queue);
    int (*destroy)(queue *Queue);
};

// 创建和销毁队列的函数声明
int initQueue(queue *Queue, int size);
int destroy(queue *Queue);

// 队列操作函数原型声明
item getItem();
int enqueue(item *data, queue *Queue);
int dequeue(item *data, queue *Queue);
int get(item *data, queue *Queue);
int isFull(queue *Queue);
int isEmpty(queue *Queue);
int clear(queue *Queue);

#endif // STATIC_QUEUE_H
