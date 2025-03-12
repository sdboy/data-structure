#include "stack.h"

int InitStackSequence(StackSequence **S) {
  if(*S != NULL) {
    return STATUS_ERROR;
  }
  *S = (StackSequence *)malloc(sizeof(StackSequence));
  (*S)->top = -1;
  return STATUS_OK;
}
int DestroyStackSequence(StackSequence **S) {
  if(*S == NULL) {
    return STATUS_ERROR;
  }
  free(*S);
  *S = NULL;
  return STATUS_OK;
}
int ClearStackSequence(StackSequence *S) {
  if(S == NULL) {
    return STATUS_ERROR;
  }
  S->top = -1;
  return STATUS_OK;
}
int StackIsEmptySequence(StackSequence *S, int *is_empty){
  if(S == NULL) {
    return STATUS_ERROR;
  }
  if(S->top == -1) {
    *is_empty = 1;
  } else {
    *is_empty = 0;
  }
  return STATUS_OK;
}
int GetTopSequence(StackSequence *S, ElementType *e) {
  if(S == NULL) {
    return STATUS_ERROR;
  }
  *e = S->data[S->top];
  return STATUS_OK;
}
int PushSequence(StackSequence *S, ElementType e) {
  if(S == NULL || S->top > STACK_MAXSIZE - 2) {
    return STATUS_ERROR;
  }
  ++S->top;
  S->data[S->top] = e;
  return STATUS_OK;
}
int PopSequence(StackSequence *S, ElementType *e) {
  if(S == NULL || S->top < 0) {
    return STATUS_ERROR;
  }
  *e = S->data[S->top];
  --S->top;
  return STATUS_OK;
}
int StackLengthSequence(StackSequence *S, int *length) {
  if(S == NULL) {
    return STATUS_ERROR;
  }
  *length = S->top + 1;
  return STATUS_OK;
}

int InitStackLink(StackLink **S) {
  if(*S != NULL) {
    return STATUS_ERROR;
  }
  *S = (StackLink *)malloc(sizeof(StackLink));
  StackLinkNodePtr node = (StackLinkNodePtr)malloc(sizeof(StackLinkNode));
  node->next = NULL;
  (*S)->top = node;
  (*S)->count = 0;
  return STATUS_OK;
}
int DestroyStackLink(StackLink **S) {
  if(*S == NULL) {
    return STATUS_ERROR;
  }
  ClearStackLink(*S);
  free((*S)->top);
  free(*S);
  *S = NULL;
  return STATUS_OK;
}
int ClearStackLink(StackLink *S) {
  if(S == NULL) {
    return STATUS_ERROR;
  }
  StackLinkNodePtr node = S->top;
  while(node->next) {
    StackLinkNodePtr s = node->next;
    node->next = node->next->next;
    free(s);
  }
  S->count = 0;
  return STATUS_OK;
}
int StackIsEmptyLink(StackLink *S, int *is_empty) {
  if(S == NULL) {
    return STATUS_ERROR;
  }
  if(S->count > 0) {
    *is_empty = 0;
  }else {
    *is_empty = 1;
  }
  return STATUS_OK;
}
int GetTopLink(StackLink *S, ElementType *e) {
  if(S == NULL || S->count < 1) {
    return STATUS_ERROR;
  }
  *e = S->top->next->data;
  return STATUS_OK;
}
int PushLink(StackLink *S, ElementType e) {
  if(S == NULL) {
    return STATUS_ERROR;
  }
  StackLinkNodePtr node = (StackLinkNodePtr)malloc(sizeof(StackLinkNode));
  node->data = e;
  node->next = S->top->next;
  S->top->next = node;
  ++S->count;
  return STATUS_OK;
}
int PopLink(StackLink *S, ElementType *e) {
  if(S == NULL || S->count < 1) {
    return STATUS_ERROR;
  }
  StackLinkNodePtr node = S->top->next;
  *e = node->data;
  S->top->next = S->top->next->next;
  free(node);
  --S->count;
  return STATUS_OK;
}
int StackLengthLink(StackLink *S, int *length) {
  if(S == NULL) {
    return STATUS_ERROR;
  }
  *length = S->count;
  return STATUS_OK;
}