#include "staticLinked.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

item getItem()
{
    item new;
    printf("Enter the new item: ");
    sacnf("%d", &new);
    return new;
}

void initList(int size, list *List)
{
    List->MAXCOUNT = size;
    List->size = 0; //* 注意静态链表的特殊性，它的指针其实是索引
    List->head = -1;
    List->space = malloc(List->MAXCOUNT * sizeof(node));
    List->available = 0;
    for (int i = List->available; i < List->MAXCOUNT - 1; i++)
    {
        List->space[i].next = i + 1;
    }
    List->space[List->MAXCOUNT - 1].next = -1;
    List->headInsert = headInsert;
    List->tailInsert = tailInsert;
    List->getIndex = getIndex;
    List->getValue = getValue;
    List->indexInsert = indexInsert;
    List->indexRemove = indexRemove;
    List->valueRemove = valueRemove;
    List->destroy = destroy;
}

void destroy(list *List)
{
    List->size = 0;
    List->head = -1;
    List->available = -1;
    List->MAXCOUNT = 0;
    free(List->space);
    return;
}

void headInsert(item *data, list *List)
{
    if (List->available == -1)
    {
        puts("List is full");
        return;
    }
    int new = List->available;
    List->head = new;
    List->available = List->space[List->available].next;
    List->space[new].data = *data;
    List->space[new].next = List->head;
    List->size++;
    return;
}

void tailInsert(item *data, list *List)
{
    if (List->available == -1)
    {
        puts("List is full");
        return;
    }
    int cursor = List->head;
    int new = List->available;
    List->available = List->space[List->available].next;
    while (List->space[cursor].next != -1)
    {
        cursor = List->space[cursor].next;
    }
    List->space[cursor].next = -1;
    List->space[cursor].data = *data;
    List->size++;
    return;
}

int getIndex(item *data, list *List)
{
    int count = -1;
    for (int cursor = List->head; cursor != -1; cursor = List->space[cursor].next)
    {
        count++;
        if (List->space[cursor].data == *data)
        {
            return count;
        }
        
    }
    return -1;
}

int getValue(item *data, int index, list *List)
{
    if (index < 1 || index > List->size)
    {
        puts("Invalid index");
        return 0;
    }
    
    int cursor = List->head;
    for (int i = 0; i < index; i++)
    {
        cursor = List->space[cursor].next;
    }
    *data = List->space[cursor].data;
    return 1;
}

void indexInsert(int index, item *data, list *List)
{
    if (index < 1 || index > List->size + 1)
    {
        puts("Invalid index");
        return;
    }
    if (List->available == -1)
    {
        puts("List is full");
        return;
    }
    if (index = 1)
    {
        int new = List->available;
        List->head = new;
        List->available = List->space[List->available].next;
        List->space[new].data = *data;
        List->space[new].next = List->head;
        List->size++;
    }
    else
    {
        int cursor = List->head;
        for (int i = 0; i < index - 2; i++)
        {
            cursor = List->space[cursor].next;
        }
        int new = List->available;
        List->space[new].next = List->space[cursor].next;
        List->space[new].data = *data;
        List->space[cursor].next = new;
        List->size++;
    }
    return;
}

void indexRemove(int index, item *data, list *List)
{
    if (index < 0 || index > List->size)
    {
        puts("Invalid index");
        return;
    }
    if (index == 1)
    {
        int head = List->head;
        List->head = List->space[head].next;
        List->space[head].next = List->available;
        List->available = head;
    }
    else
    {
        int cursor = List->head;
        for (int i = 0; i < index - 1; i++)
        {
            cursor = List->space[cursor].next;
        }
        int toDelete = List->space[cursor].next;
        List->space[cursor].next = List->space[toDelete].next;
        List->space[toDelete].next = List->available;
        List->available = toDelete;
    }
    List->size--;
    return;
}

void valueRemove(item *data, list *List)
{
    int index;
    while ((index = getIndex(data, List)) == -1)
    {
        indexRemove(index, data, List);
    }
    return;
}