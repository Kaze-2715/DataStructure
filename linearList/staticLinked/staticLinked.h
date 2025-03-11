#ifndef STATIC_LINKED_H_
#define STATIC_LINKED_H_

typedef struct node node;
typedef int item;
typedef struct staticLinked list;
struct staticLinked
{
    node *space;
    int MAXCOUNT;
    int size;
    int head;
    int available;
    void (*headInsert)(item *data, list *List);
    void (*tailInsert)(item *data, list *List);
    int (*getIndex)(item *data, list *List);
    int (*getValue)(item *data, int index, list *List);
    void (*indexInsert)(int index, item *data, list *List);
    void (*indexRemove)(int index, item *data, list *List);
    void (*valueRemove)(item *data, list *List);
    void (*destroy)(list *List);
};

struct node
{
    item data;
    int next;
};

item getItem();
void headInsert(item *data, list *List);
void tailInsert(item *data, list *List);
int getIndex(item *data, list *List);
int getValue(item *data, int index, list *List);
void indexInsert(int index, item *data, list *List);
void indexRemove(int index, item *data, list *List);
void initList(int size, list *List);
void destroy(list *List);
void valueRemove(item *data, list *List);
#endif