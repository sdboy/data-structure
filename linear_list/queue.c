#include "queue.h"

int InitQueueSequence(QueueSequence **Q) {
  if(*Q) {
    return STATUS_ERROR;
  }
  *Q = (QueueSequence *)malloc(sizeof(QueueLink));
  if(!*Q) {
    return STATUS_ERROR;
  }
  (*Q)->front = 0;
  (*Q)->rear = 0;
  return STATUS_OK;
}
int DestroyQueueSequence(QueueSequence **Q) {
  if(!*Q) {
    return STATUS_ERROR;
  }
  free(*Q);
  *Q = NULL;
  return STATUS_OK;
}
int ClearQueueSequence(QueueSequence *Q) {
  if(!Q) {
    return STATUS_ERROR;
  }
  Q->front = -1;
  Q->rear = -1;
  return STATUS_OK;
}
// int QueueIsEmptySequence(QueueLink Q, int *is_empty);
// int GetHeadSequence(QueueLink *Q, ElementType *e);
// int EnQueueSequence(QueueLink *Q, ElementType e);
// int DeQueueSequence(QueueLink *Q, ElementType *e);
// int QueueLengthSequence(QueueLink *Q);

int InitQueueLink(QueueLink **Q) {
  if(*Q != NULL) {
    return STATUS_ERROR;
  }
  *Q = (QueueLink *)malloc(sizeof(QueueLink));
  if(!*Q) {
    return STATUS_ERROR;
  }
  QueueLinkNodePtr node = (QueueLinkNodePtr)malloc(sizeof(QueueLinkNode));
  if(!node) {
    return STATUS_ERROR;
  }
  node->next = NULL;
  (*Q)->front = node;
  (*Q)->rear = node;
  return STATUS_OK;
}
int DestroyQueueLink(QueueLink **Q) {
  if(*Q == NULL) {
    return STATUS_ERROR;
  }
  ClearQueueLink(*Q);
  free((*Q)->front);
  free(*Q);
  *Q = NULL;
  return STATUS_OK;
}
int ClearQueueLink(QueueLink *Q) {
  if(Q == NULL) {
    return STATUS_ERROR;
  }
  QueueLinkNodePtr node = Q->front;
  while(node->next) {
    QueueLinkNodePtr q = node->next;
    node->next = node->next->next;
    free(q);
  }
  Q->rear = Q->front;
  return STATUS_OK;
}
int QueueIsEmptyLink(QueueLink *Q, int *is_empty) {
  if(Q == NULL) {
    return STATUS_ERROR;
  }
  if(Q->front == Q->rear) {
    *is_empty = 1;
  } else {
    *is_empty = 0;
  }
  return STATUS_OK;
}
int GetHeadLink(QueueLink *Q, ElementType *e) {
  if(Q == NULL || (Q->front == Q->rear)) {
    return STATUS_ERROR;
  }
  *e = Q->front->next->data;
  return STATUS_OK;
}
int EnQueueLink(QueueLink *Q, ElementType e) {
  if(Q == NULL) {
    return STATUS_ERROR;
  }
  QueueLinkNodePtr node = (QueueLinkNodePtr)malloc(sizeof(QueueLinkNode));
  if(!node) {
    return STATUS_ERROR;
  }
  node->data = e;
  node->next = NULL;
  Q->rear->next = node;
  Q->rear = node;
  return STATUS_OK;
}
int DeQueueLink(QueueLink *Q, ElementType *e) {
  if(Q == NULL || (Q->front == Q->rear)) {
    return STATUS_ERROR;
  }
  QueueLinkNodePtr node = Q->front->next;
  *e = node->data;
  Q->front->next = Q->front->next->next;
  if(Q->rear == node) {
    Q->rear = Q->front;
  }
  free(node);
  return STATUS_OK;
}
int QueueLengthLink(QueueLink *Q, int *length) {
  if(Q == NULL) {
    return STATUS_ERROR;
  }
  if(Q->front == Q->rear) {
    *length = 0;
  }else {
    QueueLinkNodePtr node = Q->front;
    int i = 0;
    while(node->next) {
      node = node->next;
      ++i;
    }
    *length = i;
  }
  return STATUS_OK;
}