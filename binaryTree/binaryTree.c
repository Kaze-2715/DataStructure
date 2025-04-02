#include <stdio.h>
#include <stdlib.h>
#include "binaryTree.h"

void preOrder(Node *node);

static void inOrder(Node *node)
{
    // Recursive Implementation
    if (node == NULL)
    {
        return;
    }
    inOrder(node->leftChild);
    printf("%d ", node->data);
    inOrder(node->rightChild);
    return;
    // Non-recursive Implementation
}

void postOrder(Node *node);

//? 释放子树的时候应该后序遍历吧？
static void destroySubTree(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    destroySubTree(node->leftChild);
    destroySubTree(node->rightChild);
    free(node);
    return;
}

static Node *searchvalue(Node *root, item toSearch)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == toSearch)
    {
        return root;
    }
    Node *Result = searchValue(root->leftChild, toSearch);
    if (Result == NULL)
    {
        Result = searchValue(root->rightChild, toSearch);
    }
    return Result;
}

static Node *searchParent(Node *root, Node *toSearch)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->leftChild == toSearch || root->rightChild == toSearch)
    {
        return root;
    }
    Node *result = searchParent(root->leftChild, toSearch);
    if (result == NULL)
    {
        result = searchParent(root->rightChild, toSearch);
    }
    return result;
}

void destroy(Tree *tree)
{
    if (tree == NULL)
    {
        return;
    }
    if (tree->root == NULL)
    {
        return;
    }
    destroySubTree(tree->root);
    tree->root == NULL;
    return;
}

Node *parent(Tree *tree, Node *node)
{
    if (tree == NULL)
    {
        return NULL;
    }
    if (tree->root == NULL)
    {
        return NULL;
    }
    
    return searchParent(tree->root, node);
}

Node *getLeftChild(Node *node)
{
    return node->leftChild;
}

Node *getRightChild(Node *node)
{
    return node->rightChild;
}

// TODO: Implement clear function
void clear(Tree *tree)
{
}

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

Node *searchValue(Tree *tree, item value)
{
    if (tree == NULL)
    {
        return NULL;
    }
    if (tree->root == NULL)
    {
        return NULL;
    }
    return searchvalue(tree->root, value);
}

// TODO: Implement Traverse function
void Traverse(Tree *tree)
{

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
    tree->searchValue = searchValue;
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
