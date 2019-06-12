#ifndef _MAILLIST_H
#define _MAILLIST_H
enum{
	ADD_MSG = 1,
	DEL_MSG,
	SCH_MSG,
	CHG_MSG,
	DIS_MSG,
	EMT_MSG,
};
struct MailList{
	char name[50];
	char sex[20];
	char number[20];
	char addr[200];
	int age;
}g_allMsg[1000];

extern struct MailList g_allMsg[1000];
extern int g_count;
void inputData();
void outputData();
void searchData(char * find,int searchers);
void outputSearchData(int * data);
int catchOneData(char *find);
void deleteOneData(int n);

#endif /* _MAILLIST_H*/