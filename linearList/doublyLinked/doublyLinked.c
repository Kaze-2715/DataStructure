#include "doublyLinked.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

item getItem()
{
    item new;
    printf("Enter a new item: ");
    scanf("%d", &new);
    return new;
}

void initList(list *List, int size)
{
    List->MAXSIZE = size;
    List->size = 0;
    List->head = NULL;
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
    if (List->head == NULL)
    {
        return;
    }
    node *cur = List->head;
    while (cur != NULL)
    {
        node *tmp = cur->next;
        free(cur);
        cur = tmp;
    }
    List->head = NULL;
    List->size = 0;
    return;
}

void headInsert(item *data, list *List)
{
    node *new = malloc(sizeof(node));
    new->data = *data;
    new->prev = NULL;
    new->next = List->head;
    List->head = new;
    List->size++;
    return;
}

void tailInsert(item *data, list *List)
{
    if (List->head == NULL)
    {
        node *new = malloc(sizeof(node));
        new->data = *data;
        new->prev = NULL;
        List->head = new;
        return;
    }

    node *cur = List->head;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    node *new = malloc(sizeof(node));
    new->data = *data;
    new->next = NULL;
    new->prev = cur;
    cur->next = new;
    List->size++;
    return;
}

int getIndex(item *data, list *List)
{
    if (List->head == NULL)
    {
        puts("List is empty");
        return;
    }
    int index = 0;
    for (node *cur = List->head; cur != NULL; cur = cur->next)
    {
        index++;
        if (cur->data == *data)
        {
            return index;
        }
    }
    puts("No such data");
    return 0;
}

int getValue(int index, item *data, list *List)
{
    if (List->head == NULL)
    {
        puts("List is empty");
        return;
    }
    if (index < 1 || index > List->size)
    {
        puts("Invalid index");
        return;
    }
    node *cur = List->head;
    for (int i = 1; i < index; i++)
    {
        cur = cur->next;
    }
    *data = cur->data;
    return;
}

void indexInsert(int index, item *data, list *List)
{
    if (List->head == NULL)
    {
        puts("List is empty");
        return;
    }
    if (index < 1 || index > List->size + 1)
    {
        puts("Invalid index");
        return;
    }
    if (index == 1)
    {
        headInsert(data, List);
    }
    else
    {
        int count = 1;
        node *cur = List->head;
        while (count < index - 1)
        {
            cur = cur->next;
        }
        node *new = malloc(sizeof(node));
        new->data = *data;
        new->next = cur->next;
        cur->next->prev = new;
        new->prev = cur;
    }
    List->size++;
    return;
}

void indexRemove(int index, item *data, list *List)
{
    if (List->head == NULL)
    {
        puts("List is empty");
        return;
    }
    if (index < 1 || index > List->size)
    {
        puts("Invalid index");
    }
    if (index == 1)
    {
        node *toDelete = List->head;
        List->head = toDelete->next;
        List->head->prev = NULL;
        free(toDelete);
        List->size--;
        return;
    }
    else
    {
        node *cur = List->head;
        for (int i = 1; i < index - 1; i++)
        {
            cur = cur->next;
        }
        node *toDelete = cur->next;
        toDelete->next->prev = cur;
        cur->next = toDelete->next;
        List->size--;
    }
    return;
}

void valueRemove(item *data, list *List)
{
    if (List->head == NULL)
    {
        puts("List is empty");
        return;
    }
    if (List->head->next == NULL)
    {
        if (List->head->data == *data)
        {
            free(List->head);
            List->head = NULL;
        }
        else
        {
            puts("No such data");
            return;
        }
    }
    else
    {
        for (node *cur = List->head; cur != NULL; cur = cur->next)
        {
            if (cur->data == *data)
            {
                node *prev = cur->prev;
                node *next = cur->next;
                prev->next = next;
                next->prev = prev;
                return;
            }
        }
        puts("No such data");
        return;
    }
}