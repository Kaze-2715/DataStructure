#ifndef STACK_H_
#define STACK_H_

typedef struct stack stack;
typedef int item;

struct stack
{
    int MAXSIZE;
    item *space;
    int top;
    int (*isEmpty)(stack *Stack);
    int (*isFull)(stack *Stack);
    int (*push)(item *data, stack *Stack);
    int (*pop)(item *data, stack *Stack);
    int (*get)(item *data, stack *Stack);
};

void initStack(stack *Stack, int maxsize);
void clear(stack *Stack);
int isEmpty(stack *Stack);
int isFull(stack *Stack);
int push(item *data, stack *Stack);
int pop(item *data, stack *Stack);
int get(item *data, stack *Stack);
#endif