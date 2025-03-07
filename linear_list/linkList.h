#ifndef _LINKLIST_H
#define _LINKLIST_H

#include <stdio.h>
#include <stdlib.h>

#include "statusCode.h"

typedef int ElementType;

typedef struct LinkListNode
{
	ElementType data;
	struct LinkListNode *next;
}LinkListNode, *LinkList;

int InitList(LinkList *L);
int DestroyList(LinkList *L);
int ClearList(LinkList *L);
int ListIsEmpty(LinkList *L);
int ListLength(LinkList *L);
int GetElem(LinkList *L, int i, ElementType *e);
int LocateElem(LinkList *L, ElementType e);
int HeadInsert(LinkList **L, ElementType e);
int TailInsert(LinkList **L, ElementType e);
int ListInsert(LinkList **L, int i, ElementType e);
int ListDelete(LinkList **L, int i, ElementType *e);

#endif