#include <stdio.h>

#include "statusCode.h"
#include "tree.h"
#include "sequenceList.h"
int main(int, char**){
  SequenceList *L = NULL;
  int responseCode = sequence_list_init(L);
  if(responseCode == STATUS_OK){
    printf("sequence list init success\n");
  }else{
    printf("sequence list init failed\n");
  }
  // int sequence_list_destroy(SequenceList *L);
  // int sequence_list_is_empty(SequenceList *L);
  // int sequence_list_length(SequenceList *L);
  // int sequence_list_get(SequenceList *L, int i, ElementType *e);
  // int sequence_list_insert(SequenceList *L, int i, ElementType e);
  // int sequence_list_delete(SequenceList *L, int i, ElementType *e);
  // int sequence_list_locate(SequenceList *L, ElementType e);
  // int sequence_list_clear(SequenceList *L);
  // int sequence_list_update(SequenceList *L, int i, ElementType e);

  responseCode = sequence_list_destroy(L);
  if(responseCode == STATUS_OK){
    printf("sequence list destroy success\n");
  }else{
    printf("sequence list destroy failed\n");
  }
  return 0;

}
