#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<memory.h>
#include "MailList.h"
struct MailList g_allMsg[1000];
int g_count;
int menu(){
	int choice = 0 ;
	printf("****1.添加联系人              2.删除指定联系人****\n");
	printf("****3.查找指定联系人          4.修改指定联系人****\n");
	printf("****5.显示所有联系人          6.清空指定联系人****\n");
	printf("*********************0.退出***********************\n");
	printf("请输入你要选择的选项：");
	scanf("%d", &choice); 
	return choice;
}

void MailList(){
	int op;
	int ret = 0;
	char str[256] = { 0 };
	int searchRes[101] = { 0 };
	while (1){
		op=menu();
		switch (op){
		case ADD_MSG:
			inputData();
			break;
		case DEL_MSG:
			printf("请输入你要删除的条目:\n");
			memset(str, 0, sizeof(str));
			scanf("%s", str);
			if (ret > 0){
				deleteOneData(ret);
				printf("删除成功\n");
			}
			else{
				printf("删除失败\n");
			}
			break;
		case SCH_MSG:
			printf("请输入你要检索的字符串：\n");
			memset(str, 0, sizeof(str));
			memset(searchRes, 0, sizeof(searchRes));
			scanf("%s", str);
			searchData(str, searchRes);
			outputSearchData(searchRes);
			printf("共找到%d条数据\n", searchRes[0]);
			break;
		case CHG_MSG:
			break;
		case DIS_MSG:
			outputData();
			break;
		case EMT_MSG:
			memset(g_allMsg, 0, g_count*sizeof(struct MailList));
			g_count = 0;
			break;
		case -1:
			printf("输入有误，请重新输入\n");
			break;
		default:
			printf("输入有误！\n");
		}
	}
}

int main(){

	MailList();
	system("pause");
	return 0;
}