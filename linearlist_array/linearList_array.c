#include "linearList_array.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int initList(linearList *list)
{
    int status = LIST_OK;
    if (list == NULL)
    {
        puts("NULL pointer: list");
        status = LIST_ERROR;
    }
    
    list->array = malloc(MAXSIZE * sizeof(item));
    memset(list->array, -1, sizeof(item) * MAXSIZE);
    if (list->array == NULL)
    {
        perror("Initializing list: ");
        status = LIST_ERROR;
    }
    
    list->size = 0;
    list->get = getItem;
    list->clear = clearList;
    list->destroy = destroyList;
    list->isEmpty = listIsEmpty;
    list->length = getLengthOfList;
    list->locate = locateItem;
    list->insert = insertItem;
    list->remove = removeItem;

    return status;
}

int clearList(linearList *list)
{
    int status = LIST_OK;
    if (list == NULL)
    {
        puts("NULL pointer: list");
        status = LIST_ERROR;
    }
    list->size = 0;
    return LIST_OK;
}

int destroyList(linearList *list)
{
    int status = LIST_OK;
    if (list == NULL)
    {
        puts("NULL pointer: list");
        status = LIST_ERROR;
    }
    free(list->array);
    list->array = NULL;
    list->size = 0;
}

int listIsEmpty(linearList *list)
{
    int status = 0;
    if (list == NULL)
    {
        puts("NULL pointer: list");
        status = LIST_ERROR;
    }
    if (list->size == 0)
    {
        status = 1;
    }
    return status;
}

int isFull(linearList *list)
{
    int status = 0;
    if (list == NULL)
    {
        puts("NULL pointer: list");
        status = LIST_ERROR;
    }
    if (list->size == MAXSIZE)
    {
        status = 1;
    }
    return status;
}

int getLengthOfList(linearList *list)
{
    if (list == NULL)
    {
        puts("NULL pointer: list");
        return LIST_ERROR;
    }
    return list->size;
}

int locateItem(item *ptr, linearList *list)
{
    if (list == NULL)
    {
        puts("NULL pointer: list");
        return LIST_ERROR;
    }
    if (ptr == NULL)
    {
        puts("NULL pointer: ptr");
        return LIST_ERROR;
    }
    
    int length = list->size;
    for (int i = 0; i < length; i++)
    {
        if (*ptr == list->array[i])
        {
            return i + 1;
        }
        
    }
    return 0;
}

item getItem(int index, linearList *list)
{
    item result = -1;
    if (list == NULL)
    {
        puts("NULL pointer: list");
        return result;
    }
    return list->array[index - 1];
}

int insertItem(int index, item *element, linearList *list)
{
    int status = LIST_OK;
    int length = 0;
    if (list == NULL)
    {
        puts("NULL pointer: list");
        status = LIST_ERROR;
        goto end;
    }
    if (list->array == NULL)
    {
        puts("NULL pointer: list->array");
        status = LIST_ERROR;
        goto end;
    }
    if (element == NULL)
    {
        status = LIST_ERROR;
        puts("NULL pointer: element");
        goto end;
    }
    if (index > list->size)
    {
        status = LIST_ERROR;
        puts("Array out of bounds: index");
        goto end;
    }
       
    memmove(&list->array[index + 1], &list->array[index], (list->size - index) * sizeof(item));
    list->array[index] = *element;
    list->size++;
end:
    return status;
}

int removeItem(int index, item *element, linearList *list)
{
    int status = LIST_OK;
    int length = 0;
    if (list == NULL)
    {
        puts("NULL pointer: list");
        status = LIST_ERROR;
        goto end;
    }
    if (list->array == NULL)
    {
        puts("NULL pointer: list->array");
        status = LIST_ERROR;
        goto end;
    }
    if (element == NULL)
    {
        puts("NULL pointer: element");
        status = LIST_ERROR;
        goto end;
    }
    if (index > list->size)
    {
        status = LIST_ERROR;
        puts("Array out of bounds: index");
        goto end;
    }
    length = list->size;
    *element = list->array[index - 1];
    memmove(&list->array[index - 1], &list->array[index], (list->size - index) * sizeof(item));
    list->size--;
end:
    return status;
}