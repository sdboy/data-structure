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

void LinkListTest() {
  LinkList link_list = NULL;
  if(InitList(&link_list) == STATUS_OK) {
    printf("link list init success\n");
  }else{
    printf("link list init failed\n");
  }

  int is_empty = 0;
  // if(ListIsEmpty(link_list, &is_empty) == STATUS_OK) {
  //   printf("link list %d\n", is_empty);
  // } else {
  //   printf("link list failed\n");
  // }

  srand(time(0));
  // for(int i = 0; i < 12; i++) {
  //   ElementType e = rand() % 100 + 1;
  //   if(HeadInsert(link_list, e) == STATUS_OK) {
  //     printf("head insert success\n");
  //   } else {
  //     printf("head insert failed\n");
  //     break;
  //   }
  // }
  
  for(int i = 0; i < 4; i++) {
    ElementType e = rand() % 100 + 1;
    if(TailInsert(link_list, e) == STATUS_OK) {
      printf("tail insert success\n");
    } else {
      printf("tail insert failed\n");
      break;
    }
  }

  if(ClearList(link_list) ==STATUS_OK) {
    printf("clear success\n");
  } else {
    printf("clear failed\n");
  }

  // if(ListIsEmpty(link_list, &is_empty) == STATUS_OK) {
  //   printf("link list %d\n", is_empty);
  // } else {
  //   printf("link list failed\n");
  // }

  // if(ListInsert(link_list, 2, 6) == STATUS_OK) {
  //   printf("insert success\n");
  // } else {
  //   printf("insert failed\n");
  // }

  // ElementType elem = 0;
  // if(ListDelete(link_list, 6, &elem) == STATUS_OK)
  // {
  //   printf("delete success %d\n", elem);
  // }else {
  //   printf("delete failed\n");
  // }

  int list_length = 0;
  if(ListLength(link_list, &list_length) == STATUS_OK) {
    printf("get length success %d\n", list_length);
  } else {
    printf("get length failed");
  }

  // ElementType et = 0;
  // if(GetElem(link_list, 1, &et) == STATUS_OK) {
  //   printf("get elem success %d\n", et);
  // } else {
  //   printf("get elem failed\n");
  // }

  // int loc = 0;
  // if(LocateElem(link_list, 6, &loc) == STATUS_OK) {
  //   printf("get locate success %d\n", loc);
  // } else {
  //   printf("get locate failed\n");
  // }

  if(DestroyList(&link_list) == STATUS_OK) {
    printf("link list destroy success\n");
  }else{
    printf("link list destroy failed\n");
  }

}