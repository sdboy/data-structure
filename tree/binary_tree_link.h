#ifndef _BINARY_TREE_LINK_H_
#define _BINARY_TREE_LINK_H_

#include <stdlib.h>

#include "tree_status_code.h"

typedef int ElementType;

typedef struct binary_tree_link_node {
    ElementType data;
    struct binary_tree_link_node *left;
    struct binary_tree_link_node *right;
} BinaryTreeLinkNode, *BinaryTreeLinkPointer;

typedef struct binary_tree_link {
    BinaryTreeLinkPointer root;
} BinaryTreeLink;



#endif