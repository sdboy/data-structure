#include "circular_link_list.h"

int CreateCircularLinkList(CircularLinkList *CLL) {
  if(CLL == NULL) {
    return STATUS_ERROR;
  }
  LinkList link_list = NULL;
  if(InitList(&link_list) == STATUS_OK) {
    (*CLL).head = link_list;
    (*CLL).rear = link_list;
    return STATUS_OK;
  }else {
    return STATUS_ERROR;
  }
}
int IsEmptyCircularLinkList(CircularLinkList *CLL, int *is_empty) {
  if(CLL == NULL) {
    return STATUS_ERROR;
  }
  if(CLL->head == CLL->rear) {
    *is_empty = 0;
  }else {
    *is_empty = 1;
  }
  return STATUS_OK;
}
int TailInsertCircularLinkList(CircularLinkList *CLL, ElementType elem) {
  if(CLL == NULL) {
    return STATUS_ERROR;
  }
  LinkList node = (LinkList)malloc(sizeof(LinkListNode));
  node->data = elem;
  node->next = NULL;

  CLL->rear->next = node;
  CLL->rear = node;
  return STATUS_OK;
}
int HeadInsertCircularLinkList(CircularLinkList *CLL, ElementType elem) {
  if(CLL == NULL) {
    return STATUS_ERROR;
  }
  LinkList node = (LinkList)malloc(sizeof(LinkListNode));
  node->data = elem;
  node->next = CLL->head->next;

  CLL->head->next =  node;
  return STATUS_OK;
}
int GetTailElemCircularLinkList(CircularLinkList *CLL, ElementType *elem) {
  if(CLL == NULL || CLL->head->next == NULL) {
    return STATUS_ERROR;
  }
  *elem = CLL->rear->data;
  return STATUS_OK;
}
int GetHeadElemCircularLinkList(CircularLinkList *CLL, ElementType *elem) {
  if(CLL == NULL || CLL->head->next == NULL) {
    return STATUS_ERROR;
  }
  *elem = CLL->head->next->data;
  return STATUS_OK;
}

int DeleteHeadElemCircularLinkList(CircularLinkList *CLL, ElementType *elem) {
  if(CLL == NULL || CLL->head == CLL->rear) {
    return STATUS_ERROR;
  }
  LinkList node = CLL->head->next;
  *elem = node->data;
  if(CLL->head->next == CLL->rear) {
    CLL->head->next = CLL->head->next->next;
    CLL->rear = CLL->head;
  }else {
    CLL->head->next = CLL->head->next->next;
  }
  free(node);
  return STATUS_OK;
}
int ClearCircularLinkList(CircularLinkList *CLL) {
  if(CLL == NULL || CLL->head == CLL->rear) {
    return STATUS_ERROR;
  }
  LinkList node = CLL->head->next;
  while(node) {
    LinkList p = node;
    node = node->next;
    free(p);
  }
  CLL->head->next = NULL;
  CLL->rear = CLL->head;
  return STATUS_OK;
}
int DestroyCircularLinkList(CircularLinkList *CLL) {
  if(CLL == NULL) {
    return STATUS_ERROR;
  }
  ClearCircularLinkList(CLL);
  free(CLL->head);
  (*CLL).head = NULL;
  (*CLL).rear = NULL;
  return STATUS_OK;
}

