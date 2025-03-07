#include "sequenceList.h"
#include "statusCode.h"

/**
 * @brief 初始化顺序表
 */
int SequenceListInit(SequenceList **L) {
  if (*L != NULL) {
    return STATUS_ERROR;
  }
  *L = (SequenceList *)malloc(sizeof(SequenceList));
  if (*L == NULL) {
    free(*L);
    return STATUS_ERROR;
  }
  (*L)->data = (ElementType *)malloc(SEQUENCE_LIST_MAX_SIZE * sizeof(ElementType));
  if ((*L)->data == NULL) {
    free(*L);
    return STATUS_ERROR;
  }
  (*L)->length = 0;
  return STATUS_OK;
}

/**
 * @brief 销毁顺序表
 */
int SequenceListDestroy(SequenceList **L) {
  if (*L == NULL) {
    return STATUS_ERROR;
  }
  free((*L)->data);
  free(*L);
  *L = NULL;
  return STATUS_OK;
}
/**
 * @brief 判断顺序表是否为空
 */
int SequenceListIsEmpty(SequenceList *L) {
  if (L == NULL) {
    return STATUS_ERROR;
  }
  return L->length == 0;
}

/**
 * @brief 获取顺序表长度
 */
int SequenceListLength(SequenceList *L, int *length) {
  if (L == NULL) {
    return STATUS_ERROR;
  }
  *length = L->length;
  return STATUS_OK;
}

/**
 * @brief 获取顺序表第i个元素
 */
int SequenceListGet(SequenceList *L, int i, ElementType *e) {
  if (L == NULL || i < 1 || i > L->length) {
    return STATUS_ERROR;
  }
  *e = L->data[i - 1];
  return STATUS_OK;
}

/**
 * @brief 在顺序表第i个位置插入元素e
 */
int SequenceListInsert(SequenceList *L, int i, ElementType e) {
  int c = L->length;
  if (L == NULL || i < 1 || i > L->length + 1) {
    return STATUS_ERROR;
  }
  if (L->length >= SEQUENCE_LIST_MAX_SIZE) {
    return STATUS_ERROR;
  }
  
  for (int j = L->length; j >= i; j--) {
    L->data[j] = L->data[j - 1];
  }
  L->data[i - 1] = e;
  L->length++;
  return STATUS_OK;
}
/**
 * @brief 删除顺序表第i个元素
 */
int SequenceListDelete(SequenceList *L, int i, ElementType *e) {
  if (L == NULL || i < 1 || i > L->length) {
    return STATUS_ERROR;
  }
  *e = L->data[i - 1];
  for (int j = i; j < L->length; j++) {
    L->data[j - 1] = L->data[j];
  }
  L->length--;
  return STATUS_OK;
}

/**
 * @brief 查找顺序表元素e的位置
 */
int SequenceListLocate(SequenceList *L, ElementType e, int *index) {
  if (L == NULL) {
    return STATUS_ERROR;
  }
  for (int i = 0; i < L->length; i++) {
    if (L->data[i] == e) {
      *index = i + 1;
      return STATUS_OK;
    }
  }
  return STATUS_ERROR;
}
/**
 * @brief 清空顺序表
 */
int SequenceListClear(SequenceList *L) {
  if (L == NULL) {
    return STATUS_ERROR;
  }
  L->length = 0;
  return STATUS_OK;
}

/**
 * @brief 更新顺序表第i个元素
 */
int SequenceListUpdate(SequenceList *L, int i, ElementType e) {
  if (L == NULL || i < 1 || i > L->length) {
    return STATUS_ERROR;
  }
  L->data[i - 1] = e;
  return STATUS_OK;
}