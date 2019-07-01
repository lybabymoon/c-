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
		plist->_head = plist->_head->_next;           //旧头等于next
		free(tmp);                                    //free释放旧头
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
//void SListInsertFront(SListNode* plist, SLTDataType x){       //前插 没有实现    尽可能不要采用前插操作
//	assert(plist);
//	SListNode * cur;
//	SListNode * newdata = (SListNode *)malloc(sizeof(SListNode));
//
//	if (plist->_head->_data == x){
//
//	}
//
//}
void SListReverse(SList* plist){                      //反转一个单链表
	assert(plist->_head);
#if 0
	SListNode* tmp = plist->_head->_next;
	SListNode * cur = plist->_head;
	while(tmp){
		cur->_next=tmp->_next;            //将cur 和 tmp指向下一个节点
		tmp->_next = plist->_head;        //将头指向要插入的节点之前
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
	SListNode* tmp = plist->_head->_next;    //记录next
	SListNode * cur = plist->_head;
	cur->_next = NULL;    //断链，将头结点和next断开
	while(tmp){            //每次循环都要完成断链，然后和旧头重新成链的过程
		plist->_head = tmp;    //换新头，tmp位置成为新的头，旧头成了它的第一个节点
		tmp = tmp->_next;      //记录下一次循环中tmp的位置,tmp在这次循环中已经用完，并且后边马上要进行断链，所以要在这里
		plist->_head->_next = cur;    //断链与旧头形成新链
		cur = plist->_head;         //记录旧头的位置方便下次循环成链

	}
#endif
}
//单链表只能合流不能分流