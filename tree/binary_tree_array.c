#include "binary_tree_array.h"

/**
 * 初始化二叉树
 * data值为0表示空，-1表示结束
 * @param tree 二叉树
 */
int BinaryTreeArrayInit(BinaryTreeArray tree) {
  if(tree == NULL) {
    return TREE_STATUS_ERROR;
  }
  for(int i = 0; i < BINARY_TREE_ARRAY_MAX_SIZE; i++) {
    tree[i].data = 0;
  }
  
  return TREE_STATUS_OK;
}

/**
 * 插入结点
 * @param tree 二叉树
 * @param data 插入的数据
 * @param level 插入的结点在二叉树中的层数
 * @param num 插入的结点在二叉树中当前层的位置
 * @return 状态码
 */
int BinaryTreeArrayInsert(BinaryTreeArray tree, ElementType data, int level, int num) {
  if(tree == NULL) {
    return TREE_STATUS_ERROR;
  }
  if(level < 1 || num < 1 || num > 1 << (level - 1)) {
    return TREE_STATUS_ERROR;
  }
  if(level > 1 && 1 << (level - 2) + num > BINARY_TREE_ARRAY_MAX_SIZE) {
    return TREE_STATUS_ERROR;
  }
  if(level == 1 && num != 1) {
    return TREE_STATUS_ERROR;
  }
  tree[(1 << (level - 1)) - 1 + num - 1].data = data;
  return TREE_STATUS_OK;
}

/**
 * 递归前序遍历二叉树
 * @param tree 二叉树
 * @param i 当前结点在数组中下标
 * @return 状态码
 */
int BinaryTreeArrayPreOrderTraverse(BinaryTreeArray tree, int i) {
  if(tree == NULL) {
    return TREE_STATUS_ERROR;
  }
  if(i < 0 || i >= BINARY_TREE_ARRAY_MAX_SIZE) {
    return TREE_STATUS_ERROR;

  }
  if(tree[i].data != 0 && tree[i].data != -1) {
    printf("%d ", tree[i].data);
    BinaryTreeArrayPreOrderTraverse(tree, i * 2 + 1);
    BinaryTreeArrayPreOrderTraverse(tree, i * 2 + 2);
  } else {
    return TREE_STATUS_OK;
  }
}

/**
 * 递归中序遍历二叉树
 * @param tree 二叉树
 * @param i 当前结点在数组中下标
 * @return 状态码
 */
int BinaryTreeArrayInOrderTraverse(BinaryTreeArray tree, int i) {
  if(tree == NULL) {
    return TREE_STATUS_ERROR;
  }
  if(i < 0 || i >= BINARY_TREE_ARRAY_MAX_SIZE) {
    return TREE_STATUS_ERROR;
  }
  if(tree[i].data != 0 && tree[i].data != -1) {
    BinaryTreeArrayInOrderTraverse(tree, i * 2 + 1);
    printf("%d ", tree[i].data);
    BinaryTreeArrayInOrderTraverse(tree, i * 2 + 2);
  }
  return TREE_STATUS_OK;
}

/**
 * 递归后序遍历二叉树
 * @param tree 二叉树
 * @param i 当前结点在数组中下标
 * @return 状态码
 */
int BinaryTreeArrayPostOrderTraverse(BinaryTreeArray tree, int i) {
  if(tree == NULL) {
    return TREE_STATUS_ERROR;
  }
  if(i < 0 || i >= BINARY_TREE_ARRAY_MAX_SIZE) {
    return TREE_STATUS_ERROR;
  }
  if(tree[i].data != 0 && tree[i].data != -1) {
    BinaryTreeArrayPostOrderTraverse(tree, i * 2 + 1);
    BinaryTreeArrayPostOrderTraverse(tree, i * 2 + 2);
    printf("%d ", tree[i].data);
  }
  return TREE_STATUS_OK;
}
/**
 * 以当前结点为根结点，求二叉树的高度
 * @param tree 二叉树
 * @param i 当前结点在数组中下标
 * @param level 二叉树的高度
 * @return 状态码
 */
int BinaryTreeArrayGetLevel(BinaryTreeArray tree, int i, int *level) {
  if(tree == NULL) {
    return TREE_STATUS_ERROR;
  }
  if(i < 0 || i >= BINARY_TREE_ARRAY_MAX_SIZE) {
    return TREE_STATUS_ERROR;
  }
  int j = 0;
  int is_null = 1;
  while(tree[j].data != -1) {
    if(tree[j].data != 0) {
      is_null = 0;
    }
    ++j;
  }
  if(is_null == 1 || i >= j || tree[i].data == 0) {
    return TREE_STATUS_ERROR;
  }
  *level = BinaryTreeArrayGetSubLevel(tree, i, j);
  return TREE_STATUS_OK;
}

/**
 * 递归求二叉树的高度
 * @param tree 二叉树
 * @param i 当前结点在数组中下标
 * @param length 二叉树的长度
 * @return 二叉树的高度
 */
int BinaryTreeArrayGetSubLevel(BinaryTreeArray tree, int i, int length) {
  if(i >= length) {
    return 0;
  }
  if(tree[i].data == 0) {
    return 0;
  }
  int ld = 0;
  int rd = 0;
  ld = BinaryTreeArrayGetSubLevel(tree, i * 2 + 1, length);
  rd = BinaryTreeArrayGetSubLevel(tree, i * 2 + 2, length);
  return ld > rd ? ld + 1 : rd + 1;
}
int BinaryTreeArrayDestroy(BinaryTreeArray tree) {
  if(tree == NULL) {
    return TREE_STATUS_ERROR;
  }

  for(int i = 0; i < BINARY_TREE_ARRAY_MAX_SIZE; i++) {
    tree[i].data = 0;
  }
  
  return TREE_STATUS_OK;
}