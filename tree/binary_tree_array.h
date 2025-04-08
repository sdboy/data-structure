#ifndef _BINARY_TREE_ARRAY_H_
#define _BINARY_TREE_ARRAY_H_

#include <stdlib.h>

#include "tree_status_code.h"

#define BINARY_TREE_ARRAY_MAX_SIZE 100

typedef int ElementType;

typedef struct binary_tree_array
{
  ElementType data;
}BinaryTreeArrayType, BinaryTreeArray[BINARY_TREE_ARRAY_MAX_SIZE];

int BinaryTreeArrayInit(BinaryTreeArray tree);
int BinaryTreeArrayInsert(BinaryTreeArray tree, ElementType data, int level, int num);
int BinaryTreeArrayBeforeQuery(BinaryTreeArray tree);
int BinaryTreeArrayDestroy(BinaryTreeArray tree);

#endif