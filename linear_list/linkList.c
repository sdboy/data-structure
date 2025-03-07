#include "linkList.h"

int InitList(LinkList *L) {
  if(*L != NULL) {
    return STATUS_ERROR;
  }
  *L = (LinkList)malloc(sizeof(LinkListNode));
  if(*L == NULL) {
    return STATUS_ERROR;
  }
  (*L)->next = NULL;
  return STATUS_OK;
}
int DestroyList(LinkList *L) {
  if(*L == NULL) {
    return STATUS_ERROR;
  }
  while(*L != NULL) {
    LinkListNode *p = *L;
    *L = (*L)->next;
    free(p);
  }
  return STATUS_OK;
}
// int ClearList(LinkList *L);
// int ListIsEmpty(LinkList *L);
// int ListLength(LinkList *L);
// int GetElem(LinkList *L, int i, ElementType *e);
// int LocateElem(LinkList *L, ElementType e);
// int HeadInsert(LinkList **L, ElementType e);
// int TailInsert(LinkList **L, ElementType e);
// int ListInsert(LinkList **L, int i, ElementType e);
// int ListDelete(LinkList **L, int i, ElementType *e);