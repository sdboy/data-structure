#ifndef _CIRCULAR_LINK_LIST_H
#define _CIRCULAR_LINK_LIST_H

#include <stdio.h>
#include <stdlib.h>

#include "link_list.h"
#include "statusCode.h"

typedef struct circular_link_list {
  LinkListNode *head;
  LinkListNode *rear;
}CircularLinkList;

int CreateCircularLinkList(CircularLinkList *CLL);
int IsEmptyCircularLinkList(CircularLinkList *CLL, int *is_empty);
int TailInsertCircularLinkList(CircularLinkList *CLL, ElementType elem);
int HeadInsertCircularLinkList(CircularLinkList *CLL, ElementType elem);
int GetTailElemCircularLinkList(CircularLinkList *CLL, ElementType *elem);
int GetHeadElemCircularLinkList(CircularLinkList *CLL, ElementType *elem);
int DeleteHeadElemCircularLinkList(CircularLinkList *CLL, ElementType *elem);
int ClearCircularLinkList(CircularLinkList *CLL);
int DestroyCircularLinkList(CircularLinkList *CLL);

#endif



