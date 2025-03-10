#include <stdio.h>
#include <stdlib.h>
#include "linearList.h"

item getItem()
{
    item data = 0;
    printf("Input the item: ");
    scanf("%d", &data);
    return data;
}

void initList(list *List)
{
    List->head = NULL;
    List->count = 0;
    List->headInsert = headinsert;
    List->tailInsert = tailInsert;
    List->getValue = getValue;
    List->getIndex = getIndex;
    List->indexInsert = indexInsert;
    List->indexRemove = indexRemove;
    List->destroyList = destroyList;
    List->valueRemove = valueRemove;
    return;
}

void destroyList(list *List)
{
    if (List->head == NULL)
    {
        puts("Empty list!");
        return;
    }
    
    for (node *cur = List->head; cur != NULL; cur = cur->next)
    {
        node *next = cur->next;
        free(cur);
        cur = next;
    }
    List->count = 0;
    return;
}

void headinsert(item data, list *List)
{
    node *new = malloc(sizeof(node));
    new->data = data;
    new->next = NULL;

    new->next = List->head;
    List->head = new;
    List->count++;
    return;
}

void tailInsert(item data, list *List)
{
    node *new = malloc(sizeof(node));
    new->data = data;
    new->next = NULL;

    node *tail = List->head;
    if (tail == NULL)
    {
        List->head = new;
        return;
    }
    else 
    {
        for (; tail->next != NULL; tail = tail->next);
    }

    tail->next = new;
    List->count++;
    return;
}

void indexInsert(int index, item data, list *List)
{
    if (index > List->count + 1 || index < 1)
    {
        puts("Invalid index!");
        return;
    }
    
    if (index == 1)
    {
        headinsert(data, List);
    }
    else if (index == List->count + 1)
    {
        tailInsert(data, List);
    }
    else
    {
        int target = 0;
        node *cur = List->head;
        for (; target + 2 < index; cur = cur->next);

        node *new = malloc(sizeof(node));
        new->data = data;
        new->next = cur->next;
        cur->next = new;
    }
    List->count++;
    return;
}

void indexRemove(int index, list *List)
{

    if (index > List->count || index < 1)    
    {
        puts("Invalid index!");
        return;
    }
    
    if (index == 1)
    {
        node *head = List->head;
        List->head = List->head->next;
        free(head);
    }
    else if (index == List->count)
    {
        node *beforeTail = List->head;
        while (beforeTail->next->next != NULL)
        {
            beforeTail = beforeTail->next;
        }
        free(beforeTail->next);
        beforeTail->next = NULL;
    }
    else
    {
        int target = 0;
        node *cur = List->head;
        for (; target + 2 < index; cur = cur->next);

        node *temp = cur->next;
        cur->next = cur->next->next;
        free(temp);
    }
    List->count--;
    return;
}

int getIndex(item data, list *List)
{
    int index = -1;
    for (node *ptr = List->head; ptr != NULL; ptr = ptr->next)
    {
        index++;
        if (ptr->data == data)
        {
            return index;
        }    
    }
    return index;
}

item getValue(int index, list *List)
{
    if (index > List->count || index < 1)
    {
        puts("Invalid index!");
        return -1;
    }
    item target;
    node *ptr = List->head;
    for (int i = 0; i < index - 1; i++)
    {
        ptr = ptr->next;
    }
    return ptr->data;
}

void valueRemove(item data, list *List)
{
    node *ptr = List->head;
    while(ptr->next != NULL)
    {
        if (ptr->next->data == data)
        {
            node *temp = ptr->next;
            ptr->next = ptr->next->next;
            free(temp);
        }
        ptr = ptr->next;
    }
    List->count--;
    return;
}