#include <stdio.h>
#include <stdlib.h>
#include "binaryTree.h"

void preOrder(Node *node);
void inOrder(Node *node);
void postOrder(Node *node);

void inOrder(Node *node)
{
    //Recursive Implementation
    if (node == NULL)
    {
        return;
    }
    inOrder(node->leftChild);
    printf("%d ", node->data);
    inOrder(node->rightChild);

    //Non-recursive Implementation
}
// TODO: Implement destroy function
void destroy(Tree *tree)
{
}

// TODO: Implement parent function
Node *parent(Tree *tree, Node *node)
{

}

// TODO: Implement getLeftChild function
Node *getLeftChild(Node *node)
{
    return node->leftChild;
}

// TODO: Implement getRightChild function
Node *getRightChild(Node *node)
{
    return node->rightChild;
}

// TODO: Implement clear function
void clear(Tree *tree)
{
}

// TODO: Implement insertLeftChild function
Node *insertLeftChild(Node *node, item data)
{
    if (node == NULL)
    {
        return NULL;
    }
    
    Node *new = malloc(sizeof(Node));
    new->data = data;
    new->leftChild = NULL;
    new->rightChild = NULL;
    node->leftChild = new;
    return new;
}

// TODO: Implement insertRightChild function
Node *insertRightChild(Node *node, item data)
{
    if (node == NULL)
    {
        return NULL;
    }

    Node *new = malloc(sizeof(Node));
    new->data = data;
    new->leftChild = NULL;
    new->rightChild = NULL;
    node->rightChild = new;
    return new;
}

// TODO: Implement Traverse function
void Traverse(Tree *tree)
{
}

// TODO: Implement searchNode function
Node *searchNode(Tree *tree, Node *node)
{
    return NULL;
}

// TODO: Implement getDepth function
int getDepth(Tree *tree)
{
    return 0;
}

// TODO: Implement getNodeCount function
int getNodeCount(Tree *tree)
{
    return 0;
}

// TODO: Implement isEmpty function
int isEmpty(Tree *tree)
{
    return (tree->root == NULL) ? 1 : 0;
}

// TODO: Implement getLeafCount function
int getLeafCount(Tree *tree)
{
    return 0;
}

// TODO: Implement preOrderTraverse function
void preOrderTraverse(Tree *tree)
{
}

// TODO: Implement inOrderTraverse function
void inOrderTraverse(Tree *tree)
{
}

// TODO: Implement postOrderTraverse function
void postOrderTraverse(Tree *tree)
{
}

// TODO: Implement levelOrderTraverse function
void levelOrderTraverse(Tree *tree)
{
}

// TODO: Implement mirror function
void mirror(Tree *tree)
{
}

// TODO: Implement isComplete function
int isComplete(Tree *tree)
{
    return 0;
}

// TODO: Implement getWidth function
int getWidth(Tree *tree)
{
    return 0;
}

// TODO: Implement findLCA function
Node *findLCA(Tree *tree, Node *node1, Node *node2)
{
    return NULL;
}

void initTree(Tree *tree)
{
    tree->root = NULL;
    tree->destroy = destroy;
    tree->parent = parent;
    tree->getLeftChild = getLeftChild;
    tree->getRightChild = getRightChild;
    tree->clear = clear;
    tree->insertLeftChild = insertLeftChild;
    tree->insertRightChild = insertRightChild;
    tree->Traverse = Traverse;
    tree->searchNode = searchNode;
    tree->getDepth = getDepth;
    tree->getNodeCount = getNodeCount;
    tree->isEmpty = isEmpty;
    tree->getLeafCount = getLeafCount;
    tree->preOrderTraverse = preOrderTraverse;
    tree->inOrderTraverse = inOrderTraverse;
    tree->postOrderTraverse = postOrderTraverse;
    tree->levelOrderTraverse = levelOrderTraverse;
    tree->mirror = mirror;
    tree->isComplete = isComplete;
    tree->getWidth = getWidth;
    tree->findLCA = findLCA;
}
