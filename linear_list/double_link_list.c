#include "double_link_list.h"

int InitDoubleLinkList(DoubleLinkListNodePtr *L) {
  if(*L != NULL) {
    return STATUS_ERROR;
  }
  *L = (DoubleLinkListNodePtr)malloc(sizeof(DoubleLinkListNode));
  (*L)->next = NULL;
  (*L)->prior = NULL;
  return STATUS_OK;
}
int DestroyDoubleLinkList(DoubleLinkListNodePtr *L) {
  if(*L == NULL) {
    return STATUS_ERROR;
  }
  ClearDoubleLinkList(*L);
  free(*L);
  *L = NULL;
  return STATUS_OK;
}
int InsertToDoubleLinkList(DoubleLinkListNode *L, int i, ElementType e) {
  if(L == NULL || i < 1) {
    return STATUS_ERROR;
  }
  int index = 0;
  DoubleLinkListNodePtr node = L;

  while(node != NULL && index < i - 1) {
    node = node->next;
    ++index;
  }

  DoubleLinkListNodePtr p = (DoubleLinkListNodePtr)malloc(sizeof(DoubleLinkListNode));
  p->data = e;

  if(i == 1 && L->next == NULL) {
    p->next = NULL;
    p->prior = L;
    L->next = p;
    return STATUS_OK;
  }

  if(node == NULL) {
    return STATUS_ERROR;
  }

  p->next = node->next;
  if(node->next != NULL) {
    node->next->prior = p;
  }
  p->prior = node;
  node->next = p;
  return STATUS_OK;
}

int RemoveFromDoubleLinkList(DoubleLinkListNode *L, int i, ElementType *e) {
  if(L == NULL && L->next == NULL || i < 1) {
    return STATUS_ERROR;
  }
  int index = 0;
  DoubleLinkListNodePtr node = L;
  while(node != NULL && index < i) {
    node = node->next;
    ++index;
  }

  if(node == NULL) {
    return STATUS_ERROR;
  }
  *e = node->data;
  node->prior->next = node->next;
  if(node->next != NULL) {
    node->next->prior = node->prior;
  }
  free(node);
  return STATUS_OK;
}

int ClearDoubleLinkList(DoubleLinkListNode *L) {
  if(L == NULL) {
    return STATUS_ERROR;
  }
  DoubleLinkListNodePtr node = L->next;
  while (node)
  {
    DoubleLinkListNodePtr p = node;
    node = node->next;
    free(p);
  }
  L->next = NULL;
  return STATUS_OK;
}
int GetElemOnDoubleLinkList(DoubleLinkListNode *L, int i, ElementType *e) {
  if(L == NULL || i < 1 || L->next == NULL) {
    return STATUS_ERROR;
  }
  int index = 0;
  DoubleLinkListNodePtr node = L;
  while(node != NULL && index < i) {
    node = node->next;
    ++index;
  }
  if(node == NULL) {
    return STATUS_ERROR;
  }
  *e = node->data;
  return STATUS_OK;
}