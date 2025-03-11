#ifndef STACK_H
#define STACK_H

typedef int item;
typedef struct stack stack;
typedef struct node node;

struct node
{
    item data;
    node *next;
};

struct stack
{
    int MAXCOUNT;
    int count;
    node *top;
    void (*clear)(stack *Stack);
    int (*isEmpty)(stack *Stack);
    int (*isFull)(stack *Stack);
    int (*push)(item data, stack *Stack);
    int (*pop)(item *buffer, stack *Stack);
    int (*get)(item *buffer, stack *Stack);
};

void initStack(stack *Stack, int size);
void clear(stack *Stack);
int isEmpty(stack *Stack);
int isFull(stack *Stack);
int push(item data, stack *Stack);
int pop(item *buffer, stack *Stack);
int get(item *buffer, stack *Stack);
#endif