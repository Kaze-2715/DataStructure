#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sharedStack.h"

void initStack(int size, sharedStack *Stack)
{
    Stack->MAXCOUNT = size;
    Stack->leftTop = -1;
    Stack->rightTop = size;
    Stack->sharedSpace = malloc(size * sizeof(item));
    Stack->leftPush = leftPush;
    Stack->rightPush = rightPush;
    Stack->leftPop = leftPop;
    Stack->rightPop = rightPop;
    Stack->getLeft = getLeft;
    Stack->getRight = getRight;
    Stack->clear = clear;
    return;
}

int leftPush(item *data, sharedStack *Stack)
{
    if (Stack->leftTop >= Stack->rightTop - 1)
    {
        puts("Stack is full");
        return 0;
    }
    Stack->sharedSpace[++(Stack->leftTop)] = *data;
    return 1;
}

int rightPush(item *data, sharedStack *Stack)
{
    if (Stack->rightTop >= Stack->leftTop + 1)
    {
        puts("Stack is full");
        return 0;
    }
    Stack->sharedSpace[--(Stack->rightTop)] = *data;
    return 1;
}

int leftPop(item *data, sharedStack *Stack)
{
    if (Stack->leftTop == -1)
    {
        puts("Stack is empty");
        return 0;
    }
    Stack->leftTop--;
    return 1;
}

int rightPop(item *data, sharedStack *Stack)
{
    if (Stack->rightTop == Stack->MAXCOUNT - 1)
    {
        puts("Stack is empty");
        return 0;
    }
    Stack->rightTop++;
    return 1;
}

int getLeft(item *data, sharedStack *Stack)
{
    if (Stack->leftTop == -1)
    {
        puts("Stack is empty");
        return 0;
    }
    *data = Stack->sharedSpace[Stack->leftTop];
    return 1;
}

int getRight(item *data, sharedStack *Stack)
{
    if (Stack->rightTop == Stack->MAXCOUNT - 1)
    {
        puts("Stack is empty");
        return 0;
    }
    *data = Stack->sharedSpace[Stack->rightTop];
    return 1;
}

int clear(sharedStack *Stack)
{
    memset(Stack->sharedSpace, 0, sizeof(item) * Stack->MAXCOUNT);
    Stack->leftTop = -1;
    Stack->rightTop = Stack->MAXCOUNT;
    return 0;
}

int destroy(sharedStack *Stack)
{
    free(Stack->sharedSpace);
    Stack->sharedSpace = NULL;
    Stack->leftTop = -1;
    Stack->rightTop = Stack->MAXCOUNT;
    return 0;
}