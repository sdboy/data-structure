#include "link_list.h"

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
  *L = NULL;
  return STATUS_OK;
}
int ClearList(LinkList L) {
  if(L == NULL) {
    return STATUS_ERROR;
  }
  LinkList p = L->next;
  while(p != NULL) {
    LinkList q = NULL;
    q = p;
    p = p->next;
    free(q);
  }
  L->next = NULL;
  return STATUS_OK;
}

int ListIsEmpty(LinkList L, int *empty) {
  if(L == NULL) {
    return STATUS_ERROR;
  }
  if(L->next == NULL) {
    *empty = 0;
  } else {

    *empty = 1;
  }
  return STATUS_OK;
}
int ListLength(LinkList L, int *length) {
  if(L == NULL){
    return STATUS_ERROR;
  }
  int c = 0;
  LinkList p = L->next;
  while(p != NULL) {
    ++c;
    p = p->next;
  }
  *length = c;
  return STATUS_OK;
}

int GetElem(LinkList L, int i, ElementType *e) {
  if(L == NULL || i < 1) {
    return STATUS_ERROR;
  }
  LinkList p = L;
  int c = 0;
  while(p != NULL && c < i) {
    p = p->next;
    ++c;
  }
  if(p == NULL) {
    return STATUS_ERROR;
  }
  *e = p->data;
  return STATUS_OK;
}

int LocateElem(LinkList L, ElementType e, int *locate) {
  if(L == NULL) {
    return STATUS_ERROR;
  }
  int c = 0;
  LinkList p = L;
  while(p != NULL) {
    p = p->next;
    ++c;
    if(p != NULL && e == p->data) {
      break;
    }
  }
  if(p == NULL) {
    return STATUS_ERROR;
  }
  *locate = c;
  return STATUS_OK;
}

/**
 * @brief 头插法添加数据元素
 */
int HeadInsert(LinkList L, ElementType e) {
  if(L == NULL) {
    return STATUS_ERROR;
  }
  LinkList p = (LinkList)malloc(sizeof(LinkListNode));
  p->data = e;
  p->next = L->next;
  L->next = p;
  return STATUS_OK;
}

/**
 * @brief 尾插法添加数据元素
 */
int TailInsert(LinkList L, ElementType e) {
  if (L == NULL)
  {
    return STATUS_ERROR;
  }
  LinkList p = NULL;
  p = L;
  while(p->next != NULL) {
    p = p->next;
  }
  LinkList s = (LinkList)malloc(sizeof(LinkListNode));
  s->data = e;
  s->next = p->next;
  p->next = s;
  return STATUS_OK;
}

/**
 * @brief 指定位置插如数据元素
 */
int ListInsert(LinkList L, int i, ElementType e) {
  if(L == NULL || i < 1) {
    return STATUS_ERROR;
  }
  LinkList p = L;
  int c = 0;
  while (p != NULL && c < i - 1)
  {
    p = p->next;
    ++c;
  }
  if(p == NULL) {
    return STATUS_ERROR;
  }
  LinkList s = (LinkList)malloc(sizeof(LinkListNode));
  s->data = e;
  s->next = p->next;
  p->next = s;
  return STATUS_OK;
}

/**
 * @brief 删除指定位置数据元素
 */
int ListDelete(LinkList L, int i, ElementType *e) {
  if(L == NULL || i < 1) {
    return STATUS_ERROR;
  }
  LinkList p = L;
  int c = 0;
  while(p->next != NULL && c < i - 1) {
    p = p->next;
    c++;
  }
  if(p->next == NULL) {
    return STATUS_ERROR;
  }
  LinkList s = p->next;
  *e = s->data;
  p->next = p->next->next;
  free(s);
  return STATUS_OK;
}