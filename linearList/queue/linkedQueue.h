#ifndef QUEUE_H_
#define QUEUE_H_

typedef int item;
typedef struct node node;
typedef struct queue queue;

struct node
{
    item data;
    node *prev;
    node *next;
};

struct queue
{
    int MAXSIZE;
    int size;
    node *front;
    node *rear;

    int (*enqueue)(item *data, queue *Queue);
    int (*dequeue)(item *data, queue *Queue);
    int (*get)(item *data, queue *Queue);
    int (*clear)(queue *Queue);
    int (*destroy)(queue *Queue);
    int (*isEmpty)(queue *Queue);
    int (*isFull)(queue *Queue);
};

item getItem();
void initQueue(queue *Queue, int maxSize);
int enqueue(item *data, queue *Queue);
int dequeue(item *data, queue *Queue);
int get(item *data, queue *Queue);
int clear(queue *Queue);
int destroy(queue *Queue);
int isEmpty(queue *Queue);
int isFull(queue *Queue);

#endif