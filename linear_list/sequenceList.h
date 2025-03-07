#ifndef _SEQUENCE_LIST_H
#define _SEQUENCE_LIST_H

#include <stdio.h>
#include <stdlib.h>

#define SEQUENCE_LIST_MAX_SIZE 100

typedef int ElementType;

typedef struct sequence_list
{
	ElementType *data;
	int length;
}SequenceList;

int SequenceListInit(SequenceList **L);
int SequenceListDestroy(SequenceList **L);
int SequenceListIsEmpty(SequenceList *L);
int SequenceListLength(SequenceList *L, int *length);
int SequenceListGet(SequenceList *L, int i, ElementType *e);
int SequenceListInsert(SequenceList *L, int i, ElementType e);
int SequenceListDelete(SequenceList *L, int i, ElementType *e);
int SequenceListLocate(SequenceList *L, ElementType e, int *index);
int SequenceListClear(SequenceList *L);
int SequenceListUpdate(SequenceList *L, int i, ElementType e);

#endif