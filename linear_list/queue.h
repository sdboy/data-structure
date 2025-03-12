#ifndef _QUEUE_H
#define _QUEUE_H

#include <stdlib.h>
#include "statusCode.h"

#define QUEUE_MAXSIZE 6

typedef int ElementType;

typedef struct queue_sequence
{
  ElementType data[QUEUE_MAXSIZE];
  int front;
  int rear;
}QueueSequence;

typedef struct queue_link_node
{
  ElementType data;
  struct queue_link_node *next;
}QueueLinkNode, *QueueLinkNodePtr;


typedef struct quequ_link {
  QueueLinkNodePtr front;
  QueueLinkNodePtr rear;
}QueueLink;

int InitQueueSequence(QueueSequence **Q);
int DestroyQueueSequence(QueueSequence **Q);
int ClearQueueSequence(QueueSequence *Q);
int QueueIsEmptySequence(QueueSequence Q, int *is_empty);
int GetHeadSequence(QueueSequence *Q, ElementType *e);
int EnQueueSequence(QueueSequence *Q, ElementType e);
int DeQueueSequence(QueueSequence *Q, ElementType *e);
int QueueLengthSequence(QueueSequence *Q);

int InitQueueLink(QueueLink **Q);
int DestroyQueueLink(QueueLink **Q);
int ClearQueueLink(QueueLink *Q);
int QueueIsEmptyLink(QueueLink *Q, int *is_empty);
int GetHeadLink(QueueLink *Q, ElementType *e);
int EnQueueLink(QueueLink *Q, ElementType e);
int DeQueueLink(QueueLink *Q, ElementType *e);
int QueueLengthLink(QueueLink *Q, int *length);

#endif