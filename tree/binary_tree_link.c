#include "binary_tree_link.h"

/**
 * @brief 二叉树链表
 * @param tree 二叉树根结点
 * @return 状态码
 */
int BinaryTreeLinkInit(BinaryTreeLinkPointer *tree, ElementType data) {
  if(*tree) {
    return TREE_STATUS_ERROR;
  }
  *tree = (BinaryTreeLinkPointer)malloc(sizeof(BinaryTreeLinkNode));
  (*tree)->data = data;
  (*tree)->parent = NULL;
  (*tree)->left = (*tree)->right = NULL;
  return TREE_STATUS_OK;
}

/**
 * @brief 二叉树链表创建
 * @param tree 二叉树结点
 * @return 状态码
 */
int BinaryTreeLinkCreate(BinaryTreeLinkPointer tree) {
  if(!tree) {
    return TREE_STATUS_ERROR;
  }
  int status = 1;
  while (status != 0)
  {
    printf("input status( 0 or 1): ");
    scanf("%d", &status);
    // 不添加子树，直接返回
    if(status == 0) {
      break;
    }
    int data = 0;
    int child_type = 0;
    printf("input data and child_type( 0 or 1): ");
    scanf("%d%d", &data, &child_type);
    if(BinaryTreeLinkInsert(tree, data, child_type) == TREE_STATUS_ERROR) {
      continue;
    };
    BinaryTreeLinkCreate(child_type == 0 ? tree->left : tree->right);
  }
  return TREE_STATUS_OK;
}

/**
 * @brief 二叉树链表插入
 * @param tree 二叉树根结点
 * @param data 插入的数据
 * @param child_type 插入的子树类型，0 左子树，1 右子树
 * @return 状态码
 */
int BinaryTreeLinkInsert(BinaryTreeLinkPointer tree, ElementType data, int child_type) {
  if(!tree) {
    return TREE_STATUS_ERROR;
  }
  if(child_type == 0) {
    if(tree->left) {
      printf("left child already exist\n");
      return TREE_STATUS_ERROR;
    }else {
      tree->left = (BinaryTreeLinkPointer)malloc(sizeof(BinaryTreeLinkNode));
      tree->left->data = data;
      tree->left->parent = tree;
      tree->left->left = NULL;
      tree->left->right = NULL;
    }
  }else if (child_type == 1) {
    if(tree->right) {
      printf("right child already exist\n");
      return TREE_STATUS_ERROR;
    }else {
      tree->right = (BinaryTreeLinkPointer)malloc(sizeof(BinaryTreeLinkNode));
      tree->right->data = data;
      tree->right->parent = tree;
      tree->right->left = NULL;
      tree->right->right = NULL;
    }
  }else {
    printf("child type error\n");
    return TREE_STATUS_ERROR;
  }
  return TREE_STATUS_OK;
}

/**
 * @brief 二叉树链表遍历
 * @param tree 二叉树根结点
 * @return 状态码
 */
int BinaryTreeLinkPreOrderTraverse(BinaryTreeLinkPointer tree) {
  if(!tree) {
    return TREE_STATUS_ERROR;
  }
  printf("%d ", tree->data);
  if(tree->left) {
    BinaryTreeLinkPreOrderTraverse(tree->left);
  }
  if(tree->right) {
    BinaryTreeLinkPreOrderTraverse(tree->right);
  }
  return TREE_STATUS_OK;
}

/**
 * @brief 二叉树链表后序遍历
 * @param tree 二叉树根结点
 * @return 状态码
 */
int BinaryTreeLinkInOrderTraverse(BinaryTreeLinkPointer tree) {
  if(!tree) {
    return TREE_STATUS_ERROR;
  }
  if(tree->left) {
    BinaryTreeLinkInOrderTraverse(tree->left);
  }
  printf("%d ", tree->data);
  if(tree->right) {
    BinaryTreeLinkInOrderTraverse(tree->right);
  }
  return TREE_STATUS_OK;
}

/**
 * @brief 二叉树链表后序遍历
 * @param tree 二叉树根结点
 * @return 状态码
 */
int BinaryTreeLinkPostOrderTraverse(BinaryTreeLinkPointer tree) {
  if(!tree) {
    return TREE_STATUS_ERROR;
  }
  if(tree->left) {
    BinaryTreeLinkPostOrderTraverse(tree->left);
  }
  if(tree->right) {
    BinaryTreeLinkPostOrderTraverse(tree->right);
  }
  printf("%d ", tree->data);
  return TREE_STATUS_OK;
}

/**
 * @brief 二叉树链表获取以当前结点为根结点的层数
 * @param tree 二叉树根结点
 * @param level 结点层数
 * @return 状态码
 */
int BinaryTreeLinkGetLevel(BinaryTreeLinkPointer tree, int *level);
int BinaryTreeLinkGetSubLevel(BinaryTreeLinkPointer tree);

/**
 * @brief 二叉树链表获取二叉树的深度
 * @param tree 二叉树当前结点
 * @param depth 当前结点到根结点的深度
 * @return 状态码
 */
int BinaryTreeLinkGetDeepth(BinaryTreeLinkPointer tree, int *depth);

/**
 * @brief 二叉树链表获取结点个数
 * @param tree 二叉树根结点
 * @param size 结点个数
 * @return 状态码
 */
int BinaryTreeLinkGetSize(BinaryTreeLinkPointer tree, int *size);

/**
 * @brief 二叉树链表删除结点，以及删除结点后的子树
 * @param tree 以当前结点为根结点的子树
 * @param data 结点数据
 * @return 状态码
 */
int BinaryTreeLinkDelete(BinaryTreeLinkPointer tree) {
  if(!tree) {
    return TREE_STATUS_ERROR;
  }
  BinaryTreeLinkDelete(tree->left);
  BinaryTreeLinkDelete(tree->right);
  if(tree->parent) {
    if(tree->parent->left == tree) {
      tree->parent->left = NULL;
    } else {
      tree->parent->right = NULL;
    }
    
  }
  free(tree);
  return TREE_STATUS_OK;
}

/**
 * @brief 二叉树链表销毁
 * @param tree 二叉树根结点
 * @return 状态码
 */
int BinaryTreeLinkDestroy(BinaryTreeLinkPointer *tree) {
  if(!(*tree)) {
    return TREE_STATUS_ERROR;
  }
  if(BinaryTreeLinkDelete(*tree) == TREE_STATUS_OK) {
    *tree = NULL;
    return TREE_STATUS_OK;
  }else {
    return TREE_STATUS_ERROR;
  }
}