#include "binary_tree_array.h"

/**
 * 初始化二叉树
 * data值为0表示空，-1表示结束
 * @param tree 二叉树
 */
int BinaryTreeArrayInit(BinaryTreeArray tree) {
  if(tree == NULL) {
    return STATUS_ERROR;
  }
  for(int i = 0; i < BINARY_TREE_ARRAY_MAX_SIZE; i++) {
    tree[i].data = 0;
  }
  
  return STATUS_OK;
}
int BinaryTreeArrayInsert(BinaryTreeArray tree, ElementType data, int level, int num) {
  if(tree == NULL) {
    return STATUS_ERROR;
  }
  if(level < 1 || num < 1 || num > 1 << (level - 1)) {
    return STATUS_ERROR;
  }
  if(level > 1 && 1 << (level - 2) + num > BINARY_TREE_ARRAY_MAX_SIZE) {
    return STATUS_ERROR;
  }
  if(level == 1) {
    tree[num - 1].data = data;
  } else {
    tree[1 << (level - 2) + num - 1].data = data;
  }
  return STATUS_OK;
}
int BinaryTreeArrayBeforeQuery(BinaryTreeArray tree);
int BinaryTreeArrayDestroy(BinaryTreeArray tree) {
  if(tree == NULL) {
    return STATUS_ERROR;
  }

  for(int i = 0; i < BINARY_TREE_ARRAY_MAX_SIZE; i++) {
    tree[i].data = 0;
  }
  
  return STATUS_OK;
}