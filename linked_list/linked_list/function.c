#include"linkedList.h"
void SListInit(SList* plist){
	plist->_head = NULL;
}
void SListDestory(SList* plist){

}
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
		plist->_head = plist->_head->_next;
		free(tmp);
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
	assert(plist);          //查找
	SListNode * cur;
	for (cur = plist->_head; cur; cur = cur->_next){
		if (cur->_data == x){
			return cur;
		}
	}
}
void SListInsertAfter(SListNode* pos, SLTDataType x){       //后插
	assert(pos);
	SListNode * cur = (SListNode *)malloc(sizeof(SListNode));
	cur->_data = x;
	cur->_next = pos->_next;
	pos->_next = cur;
}
void SListEraseAfter(SListNode* pos){    //删后                
	assert(pos);
	SListNode * tmp = pos->_next;
	pos->_next = tmp->_next;
	free(tmp);
}
void SListInsertFront(SListNode* plist, SLTDataType x){       //前插 没有实现    尽可能不要采用前插操作
	assert(plist);
	SListNode * cur;
	SListNode * newdata = (SListNode *)malloc(sizeof(SListNode));

	if (plist->_head->_data == x){

	}

}