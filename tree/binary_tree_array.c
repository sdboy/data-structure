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
int BinaryTreeArrayInOrderTraverse(BinaryTreeArray tree, int i);
int BinaryTreeArrayPostOrderTraverse(BinaryTreeArray tree, int i);
int BinaryTreeArrayDestroy(BinaryTreeArray tree) {
  if(tree == NULL) {
    return TREE_STATUS_ERROR;
  }

  for(int i = 0; i < BINARY_TREE_ARRAY_MAX_SIZE; i++) {
    tree[i].data = 0;
  }
  
  return TREE_STATUS_OK;
}