#include <stdio.h>
#include <stdlib.h>
#include "binaryTree.h"

typedef struct queueNode
{
    node *curNode;
    //* 同时作为哨兵结点中尾指针
    struct queueNode *next;
    //* 同时作为哨兵结点中头指针
    struct queueNode *before;
} queueNode;

typedef struct queue
{
    queueNode *front;
    queueNode *rear;
} *queue;

queue initQueue()
{
    queue new = malloc(sizeof(struct queue));
    new->front = NULL;
    new->rear = NULL;
    return new;
}

void destroyQueue(queue q)
{
    if (q->front && q->rear)
    {
        queueNode *cur = q->front;
        queueNode *next = NULL;
        while (cur != NULL)
        {
            next = cur->next;
            free(cur);
            cur = next;
        }
    }
    free(q);
    return;
}

int empty(queue q)
{
    return (!q->front && !q->rear) ? 1 : 0;
}

void enqueue(queue q, node *curNode)
{
    if (!q)
    {
        puts("Queue not initialized");
        return;
    }

    queueNode *new = malloc(sizeof(queueNode));
    new->curNode = curNode;
    new->before = NULL;
    new->next = NULL;

    //*队列为空
    if (!q->front && !q->rear)
    {
        q->front = new;
        q->rear = new;
    }
    else
    {
        new->before = q->rear;
        q->rear->next = new;
        q->rear = new;
    }
    return;
}

node *dequeue(queue q)
{
    if (!q)
    {
        puts("Queue not initialized");
        return NULL;
    }
    if (!q->front && !q->rear)
    {
        puts("Queue is empty");
        return NULL;
    }

    queueNode *first = q->front;
    node *curNode = first->curNode;
    if (q->front == q->rear) //! 分情况处理而不是分变量处理
    {
        q->rear = NULL;
        q->front = NULL;
    }
    else
    {
        q->front = first->next;
        q->front->before == NULL;
    }

    free(first);
    return curNode;
}

tree initTree()
{
    tree new = (tree)malloc(sizeof(node));
    return new;
}

int isEmpty(tree t)
{
    return (t == NULL ? 1 : 0);
}

void destroyTree(tree t)
{
    if (!t)
    {
        // puts("Visiting NULL ptr!");
        return;
    }

    if (!t->left && !t->right)
    {
        free(t);
        return;
    }

    destroyTree(t->left);
    destroyTree(t->right);
    free(t);
    return;
}

node *createNode(int data)
{
    node *new = malloc(sizeof(node));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}

node *insertLeft(node *Node, int data)
{
    node *new = createNode(data);
    Node->left = new;
    return new;
}

node *insertRight(node *Node, int data)
{
    node *new = createNode(data);
    Node->right = new;
    return new;
}

void setData(node *Node, int data)
{
    Node->data = data;
    return;
}

void visit(node *Node)
{
    printf("%d ", Node->data);
    return;
}

void preOrder(tree t)
{
    if (!t)
    {
        return;
    }
    visit(t);
    preOrder(t->left);
    preOrder(t->right);
    return;
}

void inOrder(tree t)
{
    if (!t)
    {
        return;
    }
    inOrder(t->left);
    visit(t);
    inOrder(t->right);
    return;
}

void postOrder(tree t)
{
    if (!t)
    {
        return;
    }
    postOrder(t->left);
    postOrder(t->right);
    visit(t);
    return;
}

void levelOrder(tree t)
{
    if (!t)
    {
        puts("empty tree");
        return;
    }
    queue nodes = initQueue();
    //! 这个层计数并不是必须的，只有我需要按行处理的时候才要加上，队列的特点天然就按行处理了。在 标准 BFS 里，我们通常 不关心层与层之间的明确分界，因为队列中的结点是按照层级顺序自然排列的（当前层处理完，下一层的结点才会被处理）。BFS 的遍历顺序本身就是层序的，无需手动记录层数。 
    int levelSize = 1;
    enqueue(nodes, t);

    while (!empty(nodes))
    {
        int nextLevelSize = 0;
        for (int i = 0; i < levelSize; i++)
        {
            node *cur = dequeue(nodes);
            visit(cur);
            if (cur->left)
            {
                enqueue(nodes, cur->left);
                nextLevelSize++;
            }
            if (cur->right)
            {
                enqueue(nodes, cur->right);
                nextLevelSize++;
            }
        }
        levelSize = nextLevelSize;
    }

    destroyQueue(nodes);
    return;
}

int getDepth(tree t)
{
    if (isEmpty(t))
    {
        return 0;
    }

    if (!t->left && !t->right)
    {
        return 1;
    }

    int left = getDepth(t->left);
    int right = getDepth(t->right);

    return (left > right) ? (left + 1) : (right + 1);
}

int getNodeCount(tree t)
{
    if (isEmpty(t))
    {
        return 0;
    }

    if (!t->left && !t->right)
    {
        return 1;
    }

    return getNodeCount(t->left) + getNodeCount(t->right);
}

int getLeafCount(tree t)
{
    if (isEmpty(t))
    {
        return 0;
    }
    
    if (!t->left && !t->right)
    {
        return 1;
    }
    //! 记得把自己算上
    return getLeafCount(t->left) + getLeafCount(t->right) + 1;
}

node *findNode(tree t, int data)
{
    if (isEmpty(t))
    {
        return NULL;
    }
    
    if (t->data == data)
    {
        return t;
    }

    node *leftResult = findNode(t, data);
    node *rightResult = findNode(t, data);

    return leftResult ? leftResult : rightResult;
}

int isComplete(tree t)
{
    //* 注意空树是完全二叉树
    if (!t)
    {
        return 1;
    }
    int hasNULL = 0;
    int iscomplete = 1;
    queue nodes = initQueue();
    enqueue(nodes, t);
    while (!empty(nodes))
    {
        node *cur = dequeue(nodes);
        if (cur == NULL)
        {
            hasNULL = 1;
        }
        else
        {
            //! 在这里判断：在遇到NULL后，后面的只能是NULL，如果不是NULL，就不是完全二叉树
            if (hasNULL)
            {
                iscomplete = 0;
                break;
            }
            enqueue(nodes, cur->left);
            enqueue(nodes, cur->right);
        }
    }
    destroyQueue(nodes);
    return iscomplete;
}

int main()
{
    // 创建如下结构的二叉树：
    //       1
    //      / \
    //     2   3
    //    / \   \
    //   4   5   6

    // 创建并初始化根节点
    node *root = createNode(1);

    // 插入节点
    node *node2 = insertLeft(root, 2);
    node *node3 = insertRight(root, 3);
    node *node4 = insertLeft(node2, 4);
    node *node5 = insertRight(node2, 5);
    node *node6 = insertRight(node3, 6);

    // 测试各种遍历方式
    printf("前序遍历: ");
    preOrder(root);
    printf("\n");

    printf("中序遍历: ");
    inOrder(root);
    printf("\n");

    printf("后序遍历: ");
    postOrder(root);
    printf("\n");

    printf("层序遍历: ");
    levelOrder(root);
    printf("\n");

    // 清理内存
    destroyTree(root);
    return 0;
}
