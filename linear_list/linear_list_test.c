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

void CircularLinkListTest() {
  CircularLinkList cll;
  cll.head = NULL;
  cll.rear = NULL;
  if(CreateCircularLinkList(&cll) == STATUS_OK) {
    printf("create success\n");
  }else {
    printf("create failed\n");
  }


  int is_empty = 0;
  if(IsEmptyCircularLinkList(&cll, &is_empty) == STATUS_OK) {
    printf("query is empty success %d\n", is_empty);
  }else {
    printf("query is empty failed\n");
  }

  if(TailInsertCircularLinkList(&cll, 156) == STATUS_OK) {
    printf("tail insert success\n");
  }else {
    printf("tail inster failed\n");
  }

  if(HeadInsertCircularLinkList(&cll, 54) == STATUS_OK) {
    printf("head insert success\n");
  }else {
    printf("head inster failed\n");
  }

  if(IsEmptyCircularLinkList(&cll, &is_empty) == STATUS_OK) {
    printf("query is empty success %d\n", is_empty);
  }else {
    printf("query is empty failed\n");
  }

  ElementType elem_tail = 0;
  if(GetTailElemCircularLinkList(&cll, &elem_tail) == STATUS_OK) {
    printf("tail elem is %d\n", elem_tail);
  }else {
    printf("query tail elem failed");
  }
  ElementType elem_head = 0;
  

  if(DeleteHeadElemCircularLinkList(&cll, &elem_head) == STATUS_OK) {
    printf("head remove success head elem is %d\n", elem_head);
  }else {
    printf("head remove failed\n");
  }

  if(ClearCircularLinkList(&cll) == STATUS_OK) {
    printf("clear success\n");
  }else {
    printf("clear failed\n");
  }

  elem_head = 0;
  if(GetHeadElemCircularLinkList(&cll, &elem_head) == STATUS_OK) {
    printf("head elem is %d\n", elem_head);
  }else {
    printf("query head elem failed\n");
  }

  if(DestroyCircularLinkList(&cll) == STATUS_OK) {
    printf("destroy success\n");
  }else {
    printf("destroy failed\n");
  }
}


void DoubleLinkListTest() {
  DoubleLinkListNodePtr L = NULL;
  if(InitDoubleLinkList(&L) == STATUS_OK) {
    printf("init success\n");
  }else {
    printf("init success\n");
  }
  if(InsertToDoubleLinkList(L, 1, 2) == STATUS_OK) {
    printf("insert success\n");
  }else {
    printf("insert failed\n");
  }
  if(InsertToDoubleLinkList(L, 2, 3) == STATUS_OK) {
    printf("insert success\n");
  }else {
    printf("insert failed\n");
  }
  if(InsertToDoubleLinkList(L, 3, 5) == STATUS_OK) {
    printf("insert success\n");
  }else {
    printf("insert failed\n");
  }

  ElementType elem = 0;
  if(RemoveFromDoubleLinkList(L, 3, &elem) == STATUS_OK) {
    printf("remove success %d\n", elem);
  }else {
    printf("remove failed\n");
  }

  if(ClearDoubleLinkList(L) == STATUS_OK) {
    printf("clear success\n");
  }else {
    printf("clear failed\n");
  }
  
  elem = 0;
  if(GetElemOnDoubleLinkList(L, 1, &elem) == STATUS_OK) {
    printf("query success %d\n", elem);
  }else {
    printf("query failed\n");
  }
  if(DestroyDoubleLinkList(&L) == STATUS_OK) {
    printf("destroy success\n");
  }else {
    printf("destroy success\n");
  }

}

void StackTest() {

  // 数组实现
  // StackSequence *S = NULL;
  // if(InitStackSequence(&S) == STATUS_OK) {
  //   printf("init success\n");
  // } else {
  //   printf("init failed\n");
  // }
  
  // for(int i = 2; i < 6; i++) {
  //   PushSequence(S, i);
  // }
  // if(ClearStackSequence(S) == STATUS_OK) {
  //   printf("clear success\n");
  // } else {
  //   printf("clear failed\n");
  // }
  // int is_empty = 0;
  // if(StackIsEmptySequence(S, &is_empty) == STATUS_OK) {
  //   printf("query is empty success %d\n", is_empty);
  // } else {
  //   printf("query is empty failed\n");
  // }
  // ElementType top_elem = 0;
  // if(GetTopSequence(S, &top_elem) == STATUS_OK) {
  //   printf("top is %d\n", top_elem);
  // } else {
  //   printf("get top failed\n");
  // }
  // if(PushSequence(S, 3) == STATUS_OK) {
  //   printf("push success\n");
  // } else {
  //   printf("push failed\n");
  // }
  // top_elem = 0;
  // if(PopSequence(S, &top_elem) == STATUS_OK) {
  //   printf("pop top is %d\n", top_elem);
  // } else {
  //   printf("pop failed\n");
  // }
  // int length = 0;
  // if(StackLengthSequence(S, &length) == STATUS_OK) {
  //   printf("stack length is %d\n", length);
  // } else {
  //   printf("query stack length failed\n");
  // }

  // if(DestroyStackSequence(&S) == STATUS_OK) {
  //   printf("destroy success\n");
  // } else {
  //   printf("destroy failed\n");
  // }

  // 链表实现
  StackLink *S = NULL;
  if(InitStackLink(&S) == STATUS_OK) {
    printf("init success\n");
  } else {
    printf("init failed\n");
  }
  for(int i = 1; i < 4; i++) {
    PushLink(S, i);
  }
  if(PushLink(S, 2) == STATUS_OK) {
    printf("push success\n");
  } else {
    printf("push failed\n");
  }
  ElementType top_elem = 0;
  if(GetTopLink(S, &top_elem) == STATUS_OK) {
    printf("get top success is %d\n", top_elem);
  } else {
    printf("get top failed\n");
  }
  top_elem = 0;
  if(PopLink(S, &top_elem) == STATUS_OK) {
    printf("pop success top is %d\n", top_elem);
  } else {
    printf("pop failed\n");
  }
  
  int is_empty = 1;
  if(StackIsEmptyLink(S, &is_empty) == STATUS_OK) {
    printf("query empty is %d\n", is_empty);
  } else {
    printf("query empty failed\n");
  }
  if(ClearStackLink(S) == STATUS_OK) {
    printf("clear success\n");
  } else {
    printf("clear failed\n");
  }
  if(StackIsEmptyLink(S, &is_empty) == STATUS_OK) {
    printf("query empty is %d\n", is_empty);
  } else {
    printf("query empty failed\n");
  }
  
  
  int length = 0;
  if(StackLengthLink(S, &length) == STATUS_OK) {
    printf("stack length is %d\n", length);
  } else {
    printf("query stack length failed\n");
  }
  if(DestroyStackLink(&S) == STATUS_OK) {
    printf("destroy success\n");
  } else {
    printf("destroy failed\n");
  }
}

void QueueTest() {
  QueueLink *Q = NULL;
  if(InitQueueLink(&Q) == STATUS_OK) {
    printf("init success\n");
  } else {
    printf("init failed\n");
  }
  
  for(int i = 2; i < 5; i++) {
    EnQueueLink(Q, i);
  }
  int is_empty = 0;
  if(QueueIsEmptyLink(Q, &is_empty) == STATUS_OK) {
    printf("query empty is %d\n", is_empty);
  } else {
    printf("query empty is failed\n");
  }
  ElementType elem = 0;
  if(GetHeadLink(Q, &elem) == STATUS_OK) {
    printf("get head is %d\n", elem);
  } else {
    printf("get head failed\n");
  }
  if(DeQueueLink(Q, &elem) == STATUS_OK) {
    printf("dequeue success %d\n", elem);
  } else {
    printf("dequeue failed\n");
  }
  if(ClearQueueLink(Q) == STATUS_OK) {
    printf("clear success\n");
  } else {
    printf("clear failed\n");
  }
  if(EnQueueLink(Q, 3) == STATUS_OK) {
    printf("enqueue success\n");
  } else {
    printf("enqueu failed\n");
  }
  
  
  int length = 0;
  if(QueueLengthLink(Q, &length) == STATUS_OK) {
    printf("query queue length is %d\n", length);
  } else {
    printf("query queue length failed\n");
  }
  if(DestroyQueueLink(&Q) == STATUS_OK) {
    printf("destroy success\n");
  } else {
    printf("destroy failed\n");
  }
}

void CircularQueueTest() {
  QueueSequence *Q = NULL;
  if(InitCircularQueueSequence(&Q) == STATUS_OK) {
    printf("init success\n");
  }else {
    printf("init failed\n");
  }
  for(int i = 3; i < 7; i++) {
    EnCircularQueueSequence(Q, i);
  }
  
  int is_empty = 0;
  if(CircularQueueIsEmptySequence(Q, &is_empty) == STATUS_OK) {
    printf("query empty is %d\n", is_empty);
  }else {
    printf("query empty failed\n");
  }
  ElementType elem;
  if(GetHeadCircularSequence(Q, &elem) == STATUS_OK) {
    printf("get head %d\n", elem);
  }else {
    printf("get head failed\n");
  }
  
  
  // if(DeCircularQueueSequence(Q, &elem) == STATUS_OK) {
  //   printf("dequeue success %d\n", elem);
  // }else {
  //   printf("dequeue failed\n");
  // }
  // if(ClearCircularQueueSequence(Q) == STATUS_OK) {
  //   printf("clear success\n");
  // }else {
  //   printf("clear failed\n");
  // }
  int length = 0;
  if(CircularQueueLengthSequence(Q, &length) == STATUS_OK) {
    printf("query length is %d\n", length);
  }else {
    printf("query length failed\n");
  }
  if(EnCircularQueueSequence(Q, 3) == STATUS_OK) {
    printf("enqueue success\n");
  }else {
    printf("enqueue failed\n");
  }
  if(DestroyCircularQueueSequence(&Q) == STATUS_OK) {
    printf("destroy success\n");
  }else {
    printf("destroy failed\n");
  }
}