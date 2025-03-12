#include "circuitLinked.h"
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
        goto end;
    }
    if (List->head->next = List->head)
    {
        free(List->head);
        List->head = NULL;
        goto end;
    }
    else
    {
        node *cur = List->head;
        node *tmp = NULL;
        do
        {
            tmp = cur->next;
            free(cur);
            cur = tmp;

        } while (cur != List->head);
        
    }
end:
    List->head = NULL;
    List->size = 0;
    List->MAXSIZE = 0;
    return;
}

void headInsert(item *data, list *List)
{
    if (List->head == NULL)
    {
        puts("List is empty");
        return;
    }
    
    if (List->size = List->MAXSIZE)
    {
        puts("List is full");
        return;
    }
    
    node *new = malloc(sizeof(node));
    new->data = *data;
    new->next = List->head;
    node *tail = List->head;
    while (tail->next != List->head)
    {
        tail = tail->next;
    }
    tail->next = new;
    List->head = new;
}

void tailInsert(item *data, list *List)
{
    if (List->size = List->MAXSIZE)
    {
        puts("List is full");
        return;
    }
    node *new = malloc(sizeof(node));
    new->data = *data;
    new->next = List->head;
    node *tail = List->head;
    while (tail->next != List->head)
    {
        tail = tail->next;
    }
    tail->next = new;
    return;
}

int getIndex(item *data, list *List)
{
    if (List->head == NULL)
    {
        puts("List is empty");
        return;
    }
    
    node *cur = List->head;
    if (cur->next == List->head)
    {
        if (cur->data == *data)
        {
            return 1;
        }
        else
        {
            puts("No such data");
            return -1;
        }
    }
    else
    {
        int index = 1;
        do
        {
            if (cur->data == *data)
            {
                return index;
            }
            else
            {
                index++;
                cur = cur->next;
            }
            
        } while (cur->next != List->head);
        
    }
    puts("No such data");
    return -1;
}

int getValue(int index, item *data, list *List)
{
    if (index < 1 || index > List->size)
    {
        puts("Invalid index");
        return 0;
    }

    node *cur = List->head;
    if (cur->next == List->head)
    {
        *data = cur->data;
    }    
    else
    {
        for (int i = 0; i < index; i++)
        {
            cur = cur->next;
        }
        *data = cur->data;
    }
    return 1;
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
    node *cur = List->head;
    if (index == 1)
    {
        headInsert(data, List);
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            cur = cur->next;
        }
        node *new = malloc(sizeof(node));
        new->data = *data;
        new->next = cur->next;
        cur->next = new;
    }
    return;
}

void indexRemove(int index, list *List)
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
    if (List->size == 1)
    {
        free(List->head);
        List->head = NULL;
    }
    else
    {
        node *cur = List->head;
        for (int i = 0; i < index - 1; i++)
        {
            cur = cur->next;
        }
        node *toDelete = cur->next;
        cur->next = toDelete->next;
        free(toDelete);
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
    if (List->size == 1)
    {
        if (List->head->data == *data)
        {
            free(List->head);
            List->head = NULL;
            List->size--;
        }
        else
        {
            puts("No such data");
            return;
        }
    }
    else
    {
        node *cur = NULL;
        for (cur = List->head; cur->next != List->head; cur = cur->next)
        {
            if (cur->next->data == *data)
            {
                node *toDelete = cur->next;
                cur->next = toDelete->next;
                free(toDelete);
                return;
            }
        }
        puts("No such data");

    }
    return;
}