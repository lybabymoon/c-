#include"linkedList.h"
void SListInit(SList* plist){
	plist->_head = NULL;
}
//void SListDestory(SList* plist){
//
//}
void SListPushFront(SList* plist, SLTDataType x){
	assert(plist);
	SListNode * cur = (SListNode *)malloc(sizeof(SListNode));
	cur->_data = x;
	cur->_next = plist->_head;
	plist->_head = cur;
}
void SListPopFront(SList* plist){
	assert(plist);
	if (plist->_head){
		SListNode * tmp = plist->_head;
		plist->_head = plist->_head->_next;           //��ͷ����next
		free(tmp);                                    //free�ͷž�ͷ
	}
}
void SListPrint(SList* plist){
	assert(plist);
	SListNode * cur;
	for (cur = plist->_head; cur; cur = cur->_next){
		printf("%d->", cur->_data);
	}
	printf("NULL\n");
}
void SListDestory(SList* plist){
	assert(plist);
	SListNode * tmp;
	while (plist->_head){
		tmp = plist->_head;
		plist->_head = plist->_head->_next;
		free(tmp);
	}
}
SListNode* SListFind(SList* plist, SLTDataType x){       
	assert(plist);          //����
	SListNode * cur;
	for (cur = plist->_head; cur; cur = cur->_next){
		if (cur->_data == x){
			return cur;
		}
	}
}
void SListInsertAfter(SListNode* pos, SLTDataType x){       //���
	assert(pos);
	SListNode * cur = (SListNode *)malloc(sizeof(SListNode));
	cur->_data = x;
	cur->_next = pos->_next;
	pos->_next = cur;
}
void SListEraseAfter(SListNode* pos){    //ɾ��                
	assert(pos);
	SListNode * tmp = pos->_next;
	pos->_next = tmp->_next;
	free(tmp);
}
//void SListInsertFront(SListNode* plist, SLTDataType x){       //ǰ�� û��ʵ��    �����ܲ�Ҫ����ǰ�����
//	assert(plist);
//	SListNode * cur;
//	SListNode * newdata = (SListNode *)malloc(sizeof(SListNode));
//
//	if (plist->_head->_data == x){
//
//	}
//
//}
void SListReverse(SList* plist){                      //��תһ��������
	assert(plist->_head);
#if 0
	SListNode* tmp = plist->_head->_next;
	SListNode * cur = plist->_head;
	while(tmp){
		cur->_next=tmp->_next;            //��cur �� tmpָ����һ���ڵ�
		tmp->_next = plist->_head;        //��ͷָ��Ҫ����Ľڵ�֮ǰ
		plist->_head = tmp;               
		tmp = cur->_next;
	}
#elif 0
	SList *reve = (SList *)malloc(sizeof(SList));
	SListInit(reve);
	SListNode * cur;
	for (cur = plist->_head; cur; cur = cur->_next){
		SListPushFront(reve, cur->_data);
	}
	SListDestory(plist);
	plist->_head = reve->_head;
#else
	SListNode* tmp = plist->_head->_next;    //��¼next
	SListNode * cur = plist->_head;
	cur->_next = NULL;    //��������ͷ����next�Ͽ�
	while(tmp){            //ÿ��ѭ����Ҫ��ɶ�����Ȼ��;�ͷ���³����Ĺ���
		plist->_head = tmp;    //����ͷ��tmpλ�ó�Ϊ�µ�ͷ����ͷ�������ĵ�һ���ڵ�
		tmp = tmp->_next;      //��¼��һ��ѭ����tmp��λ��,tmp�����ѭ�����Ѿ����꣬���Һ������Ҫ���ж���������Ҫ������
		plist->_head->_next = cur;    //�������ͷ�γ�����
		cur = plist->_head;         //��¼��ͷ��λ�÷����´�ѭ������

	}
#endif
}
//������ֻ�ܺ������ܷ���