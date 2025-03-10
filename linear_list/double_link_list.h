#ifndef _DDOUBLE_LINK_LIST
#define _DDOUBLE_LINK_LIST

#include <stdio.h>
#include <stdlib.h>

#include "statusCode.h"

typedef int ElementType;

typedef struct double_link_list_node {
  ElementType data;
  struct double_link_list_node *prior;
  struct double_link_list_node *next;
}DoubleLinkListNode, *DoubleLinkListNodePtr;

int InitDoubleLinkList(DoubleLinkListNodePtr *L);
int DestroyDoubleLinkList(DoubleLinkListNodePtr *L);
int InsertToDoubleLinkList(DoubleLinkListNode *L, int i, ElementType e);
int RemoveFromDoubleLinkList(DoubleLinkListNode *L, int i, ElementType *e);
int ClearDoubleLinkList(DoubleLinkListNode *L);
int GetElemOnDoubleLinkList(DoubleLinkListNode *L, int i, ElementType *e);

#endif
