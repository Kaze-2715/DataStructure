#include "serialStack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initStack(stack *Stack, int maxsize)
{
    Stack->MAXSIZE = maxsize;
    Stack->space = malloc(sizeof(item) * maxsize);
    Stack->top = -1;
    Stack->isEmpty = isEmpty;
    Stack->isFull = isFull;
    Stack->push = push;
    Stack->pop = pop;
    Stack->get = get;

    return;
}

void clear(stack *Stack)
{
    memset(Stack->space, 0, sizeof(item) * Stack->MAXSIZE);
    Stack->top = -1;
    return;
}

int isEmpty(stack *Stack)
{
    return (Stack->top == -1) ? 1 : 0;
}

int isFull(stack *Stack)
{
    return (Stack->top == Stack->MAXSIZE - 1) ? 1 : 0;
}

int push(item *data, stack *Stack)
{
    if (Stack->top == Stack->MAXSIZE - 1)
    {
        puts("Stack is full");
        return 0;
    }
    Stack->space[++(Stack->top)] = *data;
    return 1;
}

int pop(item *data, stack *Stack)
{
    if (Stack->top == -1)
    {
        puts("Stack is empty");
        return 0;
    }
    Stack->top--;
    return 1;
}

int get(item *data, stack *Stack)
{
    if (Stack->top == -1)
    {
        puts("Stack is empty");
        return 0;
    }
    *data = Stack->space[Stack->top];

    return 1;
}