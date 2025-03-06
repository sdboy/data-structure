#include <stdio.h>

#include "statusCode.h"
#include "tree.h"
#include "sequenceList.h"
int main(int, char**){
  SequenceList *L = NULL;
  
  int responseCode = sequence_list_init(&L);
  int c = L->length;
  if(responseCode == STATUS_OK){
    printf("sequence list init success\n");
  }else{
    printf("sequence list init failed\n");
  }
  int a[10] = {1,2,3,4,5,6,7,8,9,10};
  for(int i = 0; i < 10; i++){
    responseCode = sequence_list_insert(L, i + 1, a[i]);
    if(responseCode == STATUS_OK){
      printf("sequence list insert success\n");
    }else{
      printf("sequence list insert failed\n");
      break;
    }
  }
  if(sequence_list_insert( L, 3, 19) == STATUS_OK){
    printf("sequence list insert success\n");
  }else{
    printf("sequence list insert failed\n");
  }
  if(sequence_list_is_empty(L) == 0){
    printf("sequence list is not empty\n");
  }else{
    printf("sequence list is empty\n");
  }
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
