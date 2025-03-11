#ifndef SHAREDSTACK_H_
#define SHAREDSTACK_H_

typedef int item;
typedef struct sharedStack sharedStack;

struct sharedStack
{
    item *sharedSpace;
    int leftTop;
    int rightTop;
    int MAXCOUNT;
    int (*leftPush)(item *data, sharedStack *Stack);
    int (*rightPush)(item *data, sharedStack *Stack);
    int (*leftPop)(item *data, sharedStack *Stack);
    int (*rightPop)(item *data, sharedStack *Stack);
    int (*getLeft)(item *data, sharedStack *Stack);
    int (*getRight)(item *data, sharedStack *Stack);
    int (*clear)(sharedStack *Stack);
    int (*destroy)(sharedStack *Stack);
};

void initStack(int size, sharedStack *Stack);
int leftPush(item *data, sharedStack *Stack);
int rightPush(item *data, sharedStack *Stack);
int leftPop(item *data, sharedStack *Stack);
int rightPop(item *data, sharedStack *Stack);
int getLeft(item *data, sharedStack *Stack);
int getRight(item *data, sharedStack *Stack);
int clear(sharedStack *Stack);
int destroy(sharedStack *Stack);
#endif