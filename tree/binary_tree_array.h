#ifndef _BINARY_TREE_ARRAY_H_
#define _BINARY_TREE_ARRAY_H_

#include <stdlib.h>
#include <stdio.h>

#include "tree_status_code.h"

#define BINARY_TREE_ARRAY_MAX_SIZE 100

typedef int ElementType;

typedef struct binary_tree_array
{
  ElementType data;
}BinaryTreeArrayType, BinaryTreeArray[BINARY_TREE_ARRAY_MAX_SIZE];

int BinaryTreeArrayInit(BinaryTreeArray tree);
int BinaryTreeArrayInsert(BinaryTreeArray tree, ElementType data, int level, int num);
int BinaryTreeArrayPreOrderTraverse(BinaryTreeArray tree, int i);
int BinaryTreeArrayInOrderTraverse(BinaryTreeArray tree, int i);
int BinaryTreeArrayPostOrderTraverse(BinaryTreeArray tree, int i);
int BinaryTreeArrayGetLevel(BinaryTreeArray tree, int i, int *level);
int BinaryTreeArrayGetSubLevel(BinaryTreeArray tree, int i, int length);
int BinaryTreeArrayDestroy(BinaryTreeArray tree);

#endif