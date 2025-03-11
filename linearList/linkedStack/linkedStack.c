#include "linkedStack.h"
#include <stdio.h>
#include <stdlib.h>

void initStack(stack *Stack, int size)
{
    Stack->MAXCOUNT = size;
    Stack->top = NULL;
    Stack->count = 0;
    Stack->clear = clear;
    Stack->isEmpty = isEmpty;
    Stack->isFull = isFull;
    Stack->push = push;
    Stack->pop = pop;
    Stack->get = get;

    return;
}

void clear(stack *Stack)
{
    if (Stack->top == NULL)
    {
        puts("Stack: top ptr is NULL");
        return;
    }

    node *cur = Stack->top;
    while (cur != NULL)
    {
        node *ptr = cur->next;
        free(cur);
        cur = ptr;
    }

    Stack->count = 0;
    Stack->top = NULL;
    return;
}

int isEmpty(stack *Stack)
{
    return (Stack->count == 0) ? 1 : 0;
}

int isFull(stack *Stack)
{
    return (Stack->count == Stack->MAXCOUNT) ? 1 : 0;
}

int push(item data, stack *Stack)
{
    if (Stack->count == Stack->MAXCOUNT)
    {
        puts("Stack is full");
        return 0;
    }
    node *new = malloc(sizeof(node));
    new->data = data;
    new->next = Stack->top;
    Stack->top = new;
    Stack->count++;
    return 1;
}

int pop(item *buffer, stack *Stack)
{
    if (Stack->count == 0)
    {
        puts("Stack is empty");
        return 0;
    }
    
    node *topElement = Stack->top;
    Stack->top = topElement->next;
    *buffer = topElement->data;
    free(topElement);
    Stack->count--;
    return 1;
}

int get(item *buffer, stack *Stack)
{
    if (Stack->count == 0)
    {
        puts("Stack is empty");
        return 0;
    }

    *buffer = Stack->top->data;
    return 1;
}