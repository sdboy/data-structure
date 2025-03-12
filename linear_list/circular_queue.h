#ifndef _CIRCULAR_QUEUE_H
#define _CIRCULAR_QUEUE_H

#include <stdlib.h>

#include "queue.h"
#include "statusCode.h"

int InitCircularQueueSequence(QueueSequence **Q);
int DestroyCircularQueueSequence(QueueSequence **Q);
int ClearCircularQueueSequence(QueueSequence *Q);
int CircularQueueIsEmptySequence(QueueSequence *Q, int *is_empty);
int GetHeadCircularSequence(QueueSequence *Q, ElementType *e);
int EnCircularQueueSequence(QueueSequence *Q, ElementType e);
int DeCircularQueueSequence(QueueSequence *Q, ElementType *e);
int CircularQueueLengthSequence(QueueSequence *Q, int *length);

#endif
