#ifndef _STACK_H
#define _STACK_H

#include <stdlib.h>
#include "statusCode.h"

typedef int ElementType;

#define STACK_MAXSIZE 100

typedef struct stack_sequence
{
  ElementType data[STACK_MAXSIZE];
  int top;
}StackSequence;


typedef struct stack_link_node
{
  ElementType data;
  struct stack_link_node *next;
}StackLinkNode, *StackLinkNodePtr;


typedef struct stack_link
{
  StackLinkNodePtr top;
  int count;
}StackLink;

int InitStackSequence(StackSequence **S);
int DestroyStackSequence(StackSequence **S);
int ClearStackSequence(StackSequence *S);
int StackIsEmptySequence(StackSequence *S, int *is_empty);
int GetTopSequence(StackSequence *S, ElementType *e);
int PushSequence(StackSequence *S, ElementType e);
int PopSequence(StackSequence *S, ElementType *e);
int StackLengthSequence(StackSequence *S, int *length);

int InitStackLink(StackLink **S);
int DestroyStackLink(StackLink **S);
int ClearStackLink(StackLink *S);
int StackIsEmptyLink(StackLink *S, int *is_empty);
int GetTopLink(StackLink *S, ElementType *e);
int PushLink(StackLink *S, ElementType e);
int PopLink(StackLink *S, ElementType *e);
int StackLengthLink(StackLink *S, int *length);

#endif