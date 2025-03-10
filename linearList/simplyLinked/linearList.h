#ifndef LINEARLIST_LINKED_H_
#define LINEARLIST_LINKED_H_

typedef struct Node node;

typedef int item;

struct Node
{
    item data;
    node *next;
};

typedef struct list list;
struct list
{
    node *head;
    int count;
    void (*headInsert)(item data, list *List);
    void (*tailInsert)(item data, list *List);
    int (*getIndex)(item data, list *List);
    item (*getValue)(int index, list *List);
    void (*indexInsert)(int index, item data, list *List);
    void (*indexRemove)(int index, list *List);
    void (*valueRemove)(item data, list *List);
    void (*destroyList)(list *List);
};

item getItem();
void headinsert(item data, list *List);
void tailInsert(item data, list *List);
int getIndex(item data, list *List);
item getValue(int index, list *List);
void indexInsert(int index, item data, list *List);
void indexRemove(int index, list *List);
void initList(list *List);
void destroyList(list *List);
void valueRemove(item data, list *List);
#endif