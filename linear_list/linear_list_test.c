#include "linear_list_test.h"

void SequenceListTest() {
  
  SequenceList *L = NULL;
  
  int responseCode = SequenceListInit(&L);
  int c = L->length;
  if(responseCode == STATUS_OK){
    printf("sequence list init success\n");
  }else{
    printf("sequence list init failed\n");
  }
  int a[10] = {1,2,3,4,5,6,7,8,9,10};
  for(int i = 0; i < 10; i++){
    responseCode = SequenceListInsert(L, i + 1, a[i]);
    if(responseCode == STATUS_OK){
      printf("sequence list insert success\n");
    }else{
      printf("sequence list insert failed\n");
      break;
    }
  }

  // if(SequenceListInsert( L, 3, 19) == STATUS_OK){
  //   printf("sequence list insert success\n");
  // }else{
  //   printf("sequence list insert failed\n");
  // }
  // if(SequenceListIsEmpty(L) == 0){
  //   printf("sequence list is not empty\n");
  // }else{
  //   printf("sequence list is empty\n");
  // }

  // int length = 0;
  // if(SequenceListLength(L, &length)==STATUS_OK) {
  //   printf("sequence list length is %d\n", length);
  // }

  // ElementType e = 0;
  // if(SequenceListGet(L, 5, &e)==STATUS_OK) {
  //   printf("sequence list get is %d\n", e);
  // }

  // ElementType e = 0;
  // if(SequenceListDelete(L, 3, &e) == STATUS_OK) {
  //   printf("sequence list delete is %d\n", e);
  // }

  // ElementType e = -1;
  // if(SequenceListLocate(L, 4, &e)==STATUS_OK) {
  //   printf("sequence list locate is %d\n", e);
  // }

  // if(SequenceListClear(L)==STATUS_OK) {
  //   printf("sequence list clear length %d\n", L->length);
  // }

  // if(SequenceListUpdate(L, 3, 88)==STATUS_OK) {
  //   printf("sequence list update is %d\n", L->data[2]);
  // }

  responseCode = SequenceListDestroy(&L);
  if(responseCode == STATUS_OK){
    printf("sequence list destroy success\n");
  }else{
    printf("sequence list destroy failed\n");
  }
}