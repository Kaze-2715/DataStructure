typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node, *tree;

typedef struct threadNode
{
    int isLeftThread, isRightThread;
    struct threadNode *left, *right;
    int data;
} tNode, *tTree;

/* 基础操作 Basic Operations */
// 创建与销毁
tree initTree();             // 初始化树
void destroyTree(tree t); // 销毁树
int isEmpty(tree t);      // 判断是否为空

// 基本节点操作
node *createNode(int data);              // 创建节点
node *insertLeft(node *Node, int data);  // 插入左子节点
node *insertRight(node *Node, int data); // 插入右子节点
void setData(node *root, int data);      // 设置节点数据

/* 进阶操作 Intermediate Operations */
// 遍历操作
void preOrder(tree t);   // 前序遍历
void inOrder(tree t);    // 中序遍历
void postOrder(tree t);  // 后序遍历
void levelOrder(tree t); // 层序遍历

// 树的信息查询
int getDepth(tree t);                 // 获取树的深度
int getNodeCount(tree t);             // 获取节点总数
int getLeafCount(tree t);             // 获取叶子节点数
node *findNode(tree t, int data);     // 查找节点

/* 高级操作 Advanced Operations */
// 结构相关
int isComplete(tree t);     // 判断是否为完全二叉树
int isBalanced(tree t);     // 判断是否为平衡二叉树
void mirror(tree t);         // 镜像转换

// 复杂查询与变换
node *LCA(tree t, node *p, node *q);     // 最近公共祖先
int maxWidth(tree t);                                     // 获取最大宽度

// 迭代实现（非递归）
void preOrderIter(tree t);      // 非递归前序遍历
void inOrderIter(tree t);       // 非递归中序遍历
void postOrderIter(tree t);     // 非递归后序遍历