#ifndef __SEQUENCE_LIST_H__
#define __SEQUENCE_LIST_H__

#include <stdio.h>
#include <stdlib.h>

#define SEQUENCE_LIST_MAX_SIZE 100

typedef int ElementType;

typedef struct sequence_list
{
	ElementType *data;
	int length;
}SequenceList;

int sequence_list_init(SequenceList *L);
int sequence_list_destroy(SequenceList *L);
int sequence_list_is_empty(SequenceList *L);
int sequence_list_length(SequenceList *L);
int sequence_list_get(SequenceList *L, int i, ElementType *e);
int sequence_list_insert(SequenceList *L, int i, ElementType e);
int sequence_list_delete(SequenceList *L, int i, ElementType *e);
int sequence_list_locate(SequenceList *L, ElementType e);
int sequence_list_clear(SequenceList *L);
int sequence_list_update(SequenceList *L, int i, ElementType e);

#endif