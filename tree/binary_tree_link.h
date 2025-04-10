#ifndef _BINARY_TREE_LINK_H_
#define _BINARY_TREE_LINK_H_

#include <stdlib.h>
#include <stdio.h>

#include "tree_status_code.h"

typedef int ElementType;

typedef struct binary_tree_link_node {
    ElementType data;
    struct binary_tree_link_node *parent;
    struct binary_tree_link_node *left;
    struct binary_tree_link_node *right;
} BinaryTreeLinkNode, *BinaryTreeLinkPointer;

typedef struct binary_tree_link {
    BinaryTreeLinkPointer root;
} BinaryTreeLinkRoot, *BinaryTreeLinkRootPointer;

int BinaryTreeLinkInit(BinaryTreeLinkPointer *tree, ElementType data);
int BinaryTreeLinkCreate(BinaryTreeLinkPointer tree);
int BinaryTreeLinkInsert(BinaryTreeLinkPointer tree, ElementType data, int child_type);
int BinaryTreeLinkPreOrderTraverse(BinaryTreeLinkPointer tree);
int BinaryTreeLinkInOrderTraverse(BinaryTreeLinkPointer tree);
int BinaryTreeLinkPostOrderTraverse(BinaryTreeLinkPointer tree);
int BinaryTreeLinkGetLevel(BinaryTreeLinkPointer tree, int *level);
int BinaryTreeLinkGetSubLevel(BinaryTreeLinkPointer tree);
int BinaryTreeLinkGetDeepth(BinaryTreeLinkPointer tree, int *depth);
int BinaryTreeLinkGetSize(BinaryTreeLinkPointer tree, int *size);
int BinaryTreeLinkDelete(BinaryTreeLinkPointer tree);
int BinaryTreeLinkDestroy(BinaryTreeLinkPointer *tree);

#endif