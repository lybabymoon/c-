#include "seqList.h"
void SeqListInit(SeqList* psl, size_t capicity){  
	//��ʼ��
	assert(psl);
	psl->capicity = capicity;
	psl->array = (SLDataType *)malloc(capicity*sizeof(SeqList));
	assert(psl->array);
	psl->size = 0;
	//�п�

}
void SeqListDestory(SeqList* psl){
	assert(psl);
	if (psl->array){
		free(psl->array);
		psl->array = NULL;
		psl->size = 0;
		psl->capicity = 0;
	}
}
void CheckCapacity(SeqList* psl){

}

void SeqListPopBack(SeqList* psl){
	assert(psl || psl->size);
	psl->size--;                               //sizeǰ�ߵ������Լ�����������

}
void SeqListPushFront(SeqList* psl, SLDataType x){
	assert(psl);
	CheckCapacity(psl);
	int i = 0;
	for (i = psl->size - 1; i >= 0; i--){
		psl->array[i+1] = psl->array[i];
	}
	psl->array[0] = x;
	psl->size++;
}
void SeqListPopFront(SeqList* psl){
	assert(psl);
	psl->size--;
	int i;
	for (i = 0; i < psl->size; i++){
		psl->array[i] = psl->array[i + 1];
	}
}
void SeqListPrint(SeqList* psl){
	assert(psl);
	int i;
	for (i = 0; i < psl->size; i++){
		printf("%d ", psl->array[i]);
	}
}
int SeqListFind(SeqList* psl, SLDataType x){
	assert(psl);
	int i;
	for (i = 0; i < psl->size; i++){
		if (psl->array[i] == x){
			return i;
		}
	}
	return -1;
}
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x){

	assert(psl || psl->size >= pos);
	CheckCapacity(psl);
	int i;
	for (i = psl->size; i >= pos; i--){
		psl->array[i + 1] = psl->array[i];
	}
	psl->array[pos] = x;
	psl->size++;
}
void SeqListErase(SeqList* psl, size_t pos){
	assert(psl || psl->size > pos);
	psl->size--;
	int i;
	for (i = pos; i < psl->size; i++){
		psl->array[i] = psl->array[i + 1];
	}
}
void SeqListRemove(SeqList* psl, SLDataType x){
	assert(psl);
	int pos = SeqListFind(psl, x);
    if (pos >= 0){
	SeqListErase(psl, pos);
}
}
void SeqListModify(SeqList* psl, size_t pos, SLDataType x){                    //�޸�
	assert(psl || pos < psl->size);
	psl->array[pos] = x;
}
void SeqListBubbleSort(SeqList* psl){
	assert(psl);
	int i, j;
	SLDataType tmp;
	for (i = 0; i < psl->size - 1; i++){
		for (j = 0; j < psl->size - i - 1; j++){
			if (psl->array[j]>psl->array[j + 1]){
				tmp = psl->array[j];
				psl->array[j] = psl->array[j + 1];
				psl->array[j + 1] = tmp;
			}
		}
	}
}
int SeqListBinaryFind(SeqList* psl, SLDataType x){
	assert(psl);
	int left = 0;
	int right = psl->size - 1;
	int mid;
	//��Ҫ�ڴ�����ڲ�����
	while (left <= right){
		mid = (left + right) / 2;
		if (psl->array[mid] < x){
			left = mid + 1;
		}
		else if (psl->array[mid]>x){
			right = mid - 1;
		}
		else{
			return mid;
		}

	}
}