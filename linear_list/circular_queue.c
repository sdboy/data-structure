#include "circular_queue.h"

int InitCircularQueueSequence(QueueSequence **Q) {
  return InitQueueSequence(Q);
}
int DestroyCircularQueueSequence(QueueSequence **Q) {
  return DestroyQueueSequence(Q);
}
int ClearCircularQueueSequence(QueueSequence *Q) {
  return ClearQueueSequence(Q);
}
int CircularQueueIsEmptySequence(QueueSequence *Q, int *is_empty) {
  if(!Q) {
    return STATUS_ERROR;
  }
  if(Q->front == Q->rear) {
    *is_empty = 1;
  } else {
    *is_empty = 0;
  }
  return STATUS_OK;
}
int GetHeadCircularSequence(QueueSequence *Q, ElementType *e) {
  if(!Q || Q->front == Q->rear) {
    return STATUS_ERROR;
  }
  *e = Q->data[Q->front];
  return STATUS_OK;
}
int EnCircularQueueSequence(QueueSequence *Q, ElementType e) {
  if(!Q || ((Q->rear + 1) % QUEUE_MAXSIZE == Q->front)) {
    return STATUS_ERROR;
  }
  Q->data[Q->rear] = e;
  Q->rear = (Q->rear + 1) % QUEUE_MAXSIZE;
  return STATUS_OK;
}
int DeCircularQueueSequence(QueueSequence *Q, ElementType *e) {
  if(!Q || Q->front == Q->rear) {
    return STATUS_ERROR;
  }
  *e = Q->data[Q->front];
  Q->front = (Q->front + 1) % QUEUE_MAXSIZE;
  return STATUS_OK;
}
int CircularQueueLengthSequence(QueueSequence *Q, int *length) {
  if(!Q) {
    return STATUS_ERROR;
  }
  if(Q->front == Q->rear) {
    *length = 0;
  }else {
    *length = (Q->rear - Q->front + QUEUE_MAXSIZE) % QUEUE_MAXSIZE;
  }
  return STATUS_OK;
}