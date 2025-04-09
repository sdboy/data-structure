#include "tree_test.h"

void BinaryTreeArrayTest() {
  int node = 0;
  int index = 0;
  BinaryTreeArray arr;
  BinaryTreeArrayInit(arr);
  while(index < BINARY_TREE_ARRAY_MAX_SIZE) {
    int level = 1;
    int num = 1;
    printf("Please input the node number: ");
    scanf("%d", &node);
    if(node == 0) {
      continue;
    }else if(node == -1) {
      while((1 << (level - 1)) - 1 < index) {
        if((1 << level) - 1 > index) {
          break;
        }
        ++level;
      }
      num = index - ((1 << (level - 1)) - 1) + 1;
      BinaryTreeArrayInsert(arr, node, level, num);
      break;
    }else {
      while((1 << (level - 1)) - 1 < index) {
        if((1 << level) - 1 > index) {
          break;
        }
        ++level;
      }
      num = index - ((1 << (level - 1)) - 1) + 1;
      BinaryTreeArrayInsert(arr, node, level, num);
    }
    ++index;
  }
  BinaryTreeArrayPreOrderTraverse(arr, 0);
  BinaryTreeArrayDestroy(arr);
}

void BinaryTreeLinkTest();