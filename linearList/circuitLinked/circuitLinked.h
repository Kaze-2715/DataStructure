#ifndef CIRCUIT_LINKED_H_
#define CIRCUIT_LINKED_H_

typedef int item;
typedef struct node node;
typedef struct list list;
struct node
{
    item data;
    node *next;
};
struct list
{
    int MAXSIZE;
    int size;
    node *head;
    void (*headInsert)(item data, list *List);
    void (*tailInsert)(item data, list *List);
    int (*getIndex)(item data, list *List);
    int (*getValue)(int index, item *data, list *List);
    void (*indexInsert)(int index, item data, list *List);
    void (*indexRemove)(int index, item *data, list *List);
    void (*valueRemove)(item data, list *List);
    void (*destroy)(list *List);
};

item getItem();
void headInsert(item *data, list *List);
void tailInsert(item *data, list *List);
int getIndex(item *data, list *List);
int getValue(int index, item *data, list *List);
void indexInsert(int index, item *data, list *List);
void indexRemove(int index, item *data, list *List);
void initList(list *List, int size);
void destroy(list *List);
void valueRemove(item *data, list *List);
#endif