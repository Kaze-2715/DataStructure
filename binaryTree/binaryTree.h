typedef struct binaryTree Tree;
typedef struct treeNode Node;
typedef int item;

// 数据结构定义
struct treeNode
{
    item data;
    Node *leftChild;
    Node *rightChild;
};

struct binaryTree
{
    Node *root;

    // 基本操作
    void (*destroy)(Tree *tree);
    void (*clear)(Tree *tree);

    // 节点操作
    Node *(*insertLeftChild)(Node *node, item data);
    Node *(*insertRightChild)(Node *node, item data);
    Node *(*searchValue)(Tree *tree, item value);
    Node *(*parent)(Tree *tree, Node *node);
    Node *(*getLeftChild)(Node *node);
    Node *(*getRightChild)(Node *node);

    // 遍历操作
    void (*Traverse)(Tree *tree);
    void (*preOrderTraverse)(Tree *tree);
    void (*inOrderTraverse)(Tree *tree);
    void (*postOrderTraverse)(Tree *tree);
    void (*levelOrderTraverse)(Tree *tree);

    // 树的属性查询
    int (*getDepth)(Tree *tree);
    int (*getNodeCount)(Tree *tree);
    int (*isEmpty)(Tree *tree);
    int (*getLeafCount)(Tree *tree);
    int (*getWidth)(Tree *tree);

    // 高级操作
    void (*mirror)(Tree *tree);
    int (*isComplete)(Tree *tree);
    Node *(*findLCA)(Tree *tree, Node *node1, Node *node2);
};

// 函数声明
// 基本操作
void initTree(Tree *tree);
void destroy(Tree *tree);
void clear(Tree *tree);

// 节点操作
Node *insertLeftChild(Node *node, item data);
Node *insertRightChild(Node *node, item data);
Node *searchValue(Tree *tree, item value);
Node *parent(Tree *tree, Node *node);
Node *getLeftChild(Node *node);
Node *getRightChild(Node *node);

// 遍历操作
void Traverse(Tree *tree);
void preOrderTraverse(Tree *tree);
void inOrderTraverse(Tree *tree);
void postOrderTraverse(Tree *tree);
void levelOrderTraverse(Tree *tree);

// 树的属性查询
int getDepth(Tree *tree);
int getNodeCount(Tree *tree);
int isEmpty(Tree *tree);
int getLeafCount(Tree *tree);
int getWidth(Tree *tree);

// 高级操作
void mirror(Tree *tree);
int isComplete(Tree *tree);
Node *findLCA(Tree *tree, Node *node1, Node *node2);
