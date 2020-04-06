#ifndef _RED_BLACK_TREE_H_
#define _RED_BLACK_TREE_H_

#define RED        0    // 红色节点
#define BLACK    1    // 黑色节点

typedef int Type;

// 红黑树的节点
typedef struct RBTreeNode {
    unsigned char color;        // 颜色(RED 或 BLACK)
    Type   key;                    // 关键字(键值)
    struct RBTreeNode* left;    // 左孩子
    struct RBTreeNode* right;    // 右孩子
    struct RBTreeNode* parent;    // 父结点
}Node, * RBTree;

// 红黑树的根
typedef struct rb_root {
    Node* node;
}RBRoot;

// 创建红黑树，返回"红黑树的根"！
RBRoot* create_rbtree();

// 销毁红黑树
void destroy_rbtree(RBRoot* root);

// 将结点插入到红黑树中。插入成功，返回0；失败返回-1。
/*
* 新建结点(节点键值为key)，并将其插入到红黑树中
*
* 参数说明：
*     root 红黑树的根
*     key 插入结点的键值
* 返回值：
*     0，插入成功
*     -1，插入失败
*/
inline int insert_rbtree(RBRoot* root, Type key)
{
    Node* node;    // 新建结点

                   // 不允许插入相同键值的节点。
                   // (若想允许插入相同键值的节点，注释掉下面两句话即可！)
    if (search(root->node, key) != NULL)
        return -1;

    // 如果新建结点失败，则返回。
    if ((node = create_rbtree_node(key, NULL, NULL, NULL)) == NULL)
        return -1;

    rbtree_insert(root, node);

    return 0;
}

// 删除结点(key为节点的值)
void delete_rbtree(RBRoot* root, Type key);


// 前序遍历"红黑树"
void preorder_rbtree(RBRoot* root);
// 中序遍历"红黑树"
void inorder_rbtree(RBRoot* root);
// 后序遍历"红黑树"
void postorder_rbtree(RBRoot* root);

// (递归实现)查找"红黑树"中键值为key的节点。找到的话，返回0；否则，返回-1。
int rbtree_search(RBRoot* root, Type key);
// (非递归实现)查找"红黑树"中键值为key的节点。找到的话，返回0；否则，返回-1。
int iterative_rbtree_search(RBRoot* root, Type key);

// 返回最小结点的值(将值保存到val中)。找到的话，返回0；否则返回-1。
int rbtree_minimum(RBRoot* root, int* val);
// 返回最大结点的值(将值保存到val中)。找到的话，返回0；否则返回-1。
int rbtree_maximum(RBRoot* root, int* val);

// 打印红黑树
void print_rbtree(RBRoot* root);

#endif
