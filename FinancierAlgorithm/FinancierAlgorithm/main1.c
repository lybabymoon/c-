#if 0
#define _CRT_SECURE_NO_WARNINGS
//=====<head file>==============================================================
#include<stdio.h>
#include<windows.h>
#include<conio.h>

//=====<data structure>=========================================================
struct systemInformation
{
	int proceeding; //number of preceedings.
	int resource;   //number of resources.
	int available[6];//six kinds of resources.
	int maxResource[6];//each max element stand for the max number of one kind of resources .
	int allocation[10][6];//allocation[i][j]=k stand for proceeding[i] has been allocated k resource[j].
	int need[10][6];//need[i][j]=k stands for proceeding[i] need k resource[j] for finishing.
	int finish[10];//finish[i]=1 => proceeding[i] have been finished .
};
struct currentProceedingInformation
{
	int proceedingID;
	int need[6];
};
//=====<static variable>========================================================
struct systemInformation information;
struct currentProceedingInformation informationForCheck;
int haveBeenInitializedTag = 0;
//=====<function declare>=======================================================
char menu();//show menu UI.
void drawTable();//to show users the current system information.
void defaultInput();//use default information to run this algorithm.
void input();
void financier();//financier algorithm
int  securityCheck();//a subordinate function of financier .

//=====<mian function>========================================================== 
int main()
{
	do
	{
		char option = menu();
		switch (option)
		{
		case'1':
		{
				   input();
				   drawTable();
				   break;
		}
		case'2':
		{
				   defaultInput();
				   system("cls");
				   drawTable();
				   printf("\n[Enter]继续\n");
				   getchar();
				   break;
		}
		case'3':
		{
				   ;//nothing
				   break;
		}
		case'4':
		{
				   system("cls");
				   drawTable();
				   printf("\n[Enter]继续\n");
				   getchar();
				   goto sign;
		}
		}
		system("cls");
		financier();
	sign:;
	} while (1);
	return 0;
}

//=====<functions>============================================================== 
char menu()
{
	do
	{
		system("cls");
		printf("             银行家算法\n");
		printf("    ----------------------------\n");
		printf("\n");
		printf("        (1)---输入数据\n");
		printf("\n");
		printf("        (2)---使用默认数据\n");
		printf("\n");
		if (haveBeenInitializedTag == 1)
		{
			printf("        (3)--继续\n");
			printf("\n");
			printf("        (4)--显示系统状态\n");
			printf("\n");
		}
		printf("        (0)---退出程序\n");
		printf("\n");
		printf("    ----------------------------\n");

		printf("\n请选择:");
		char optionTag = getchar();
		if (optionTag == '0')
		{
			system("cls");
			printf("\n\n\t\t<欢迎下次使用>\n\n\t\t");
			Sleep(1000);
			exit(0);
		}
		else if (optionTag == '1' || optionTag == '2')
			return optionTag;
		else if ((optionTag == '3' || optionTag == '4') && haveBeenInitializedTag == 1)
			return optionTag;
		else
		{
			printf("\n#输入错误#");
			Sleep(500);
		}
	} while (1);
}

void defaultInput()
{
	information.proceeding = 5;
	information.resource = 3;
	information.available[0] = 3;
	information.available[1] = 3;
	information.available[2] = 2;
	information.maxResource[0] = 10;
	information.maxResource[1] = 5;
	information.maxResource[2] = 7;
	information.allocation[0][0] = 0;
	information.allocation[0][1] = 1;
	information.allocation[0][2] = 0;
	information.allocation[1][0] = 2;
	information.allocation[1][1] = 0;
	information.allocation[1][2] = 0;
	information.allocation[2][0] = 3;
	information.allocation[2][1] = 0;
	information.allocation[2][2] = 2;
	information.allocation[3][0] = 2;
	information.allocation[3][1] = 1;
	information.allocation[3][2] = 1;
	information.allocation[4][0] = 0;
	information.allocation[4][1] = 0;
	information.allocation[4][2] = 2;
	information.need[0][0] = 7;
	information.need[0][1] = 4;
	information.need[0][2] = 3;
	information.need[1][0] = 1;
	information.need[1][1] = 2;
	information.need[1][2] = 2;
	information.need[2][0] = 6;
	information.need[2][1] = 0;
	information.need[2][2] = 0;
	information.need[3][0] = 0;
	information.need[3][1] = 1;
	information.need[3][2] = 1;
	information.need[4][0] = 4;
	information.need[4][1] = 3;
	information.need[4][2] = 1;

	//finish[]=0;
	for (int i = 0; i<5; i++)
	{
		information.finish[i] = 0;
	}

	haveBeenInitializedTag = 1;
}

void input()
{
	system("cls");
	printf("输入信息\n");
	printf("---------------------------\n");
	printf("\n");

	//input proceeding 
	printf("\n请输入进程的个数:");
	int temporary = 0;
	scanf("%d", &temporary);
	if (temporary <= 0 || temporary>10)
	{
		printf("\n#输入错误,再见#\n");
		getchar();
		exit(0);
	}
	else
		information.proceeding = temporary;
	printf("\n#以下用 P0-p%d 来表示\n", temporary);

	//input resource
	printf("\n请输入资源的个数:");
	scanf("%d", &temporary);
	if (temporary <= 0 || temporary>6)
	{
		printf("\n#输入错误,再见#\n");
		getchar();
		exit(0);
	}
	else
		information.resource = temporary;
	printf("\n#以下用 A-%c 来表示", temporary + 65);

	//input maxResource
	for (int i = 0; i<information.resource; i++)
	{
		printf("\n请输入%c类资源总数:", i + 65);
		scanf("%d", &temporary);
		if (temporary <= 0)
		{
			printf("\n#输入错误,再见#");
			getchar();
			exit(0);
		}
		else
			information.maxResource[i] = temporary;
	}

	//input allocation
	for (int i = 0; i<information.proceeding; i++)
	{
		for (int j = 0; j<information.resource; j++)
		{
			printf("\n请输入P%d 当前已占有%c 类资源的数目:", i, j + 65);
			if (temporary <= 0)
			{
				printf("\n#输入错误,再见#");
				getchar();
				exit(0);
			}
			else
				information.allocation[i][j] = temporary;
		}
	}

	//input need
	for (int i = 0; i<information.proceeding; i++)
	{
		for (int j = 0; j<information.resource; j++)
		{
			printf("\n请输入P%d 当前尚需要%c 类资源的数目:", i, j + 65);
			if (temporary <= 0)
			{
				printf("\n#输入错误,再见#");
				getchar();
				exit(0);
			}
			else
				information.allocation[i][j] = temporary;
		}
	}

	//finish[]=0;
	for (int i = 0; i<information.proceeding; i++)
	{
		information.finish[i] = 0;
	}
	haveBeenInitializedTag = 1;
}

void drawTable()
{
	printf("\n\n当前系统状态:\n\n");

	printf("P :A allication/need ...\n");
	for (int i = 0; i<information.proceeding; i++)
	{
		printf("\n");
		printf("P%d: ", i);

		if (information.finish[i] == 0)
		{
			//
			for (int j = 0; j<information.resource; j++)
			{
				printf("%c %d/%d  ", j + 65, information.allocation[i][j], information.need[i][j]);
			}
			printf(";");
		}
		else
			printf("已完成");
	}
	printf("\n系统剩余: ");
	for (int i = 0; i<information.resource; i++)
	{
		printf("%c:%d ", i + 65, information.available[i]);
	}
	printf("\n");
}

void financier()
{
	system("cls");
	printf("银行家算法\n");
	printf("----------------------------\n\n");

	fflush(stdin);//empty  input block.
	printf("请输入要申请资源的程序(如 P1): ");
	int temporary = -1;
	char p;
	scanf("%c%d", &p, &temporary);
	if (temporary<0 || temporary >= information.proceeding)
	{
		printf("\n#输入错误,再见#");
		Sleep(1000);
		exit(0);
	}
	else
		informationForCheck.proceedingID = temporary;

	printf("\n");
	for (int i = 0; i<information.resource; i++)
	{
		printf("请输入 P%d 要申请 %c 类资源的数目:", informationForCheck.proceedingID, i + 65);
		scanf("%d", &temporary);
		if (temporary < 0)
		{
			printf("\n#输入错误,再见#");
			Sleep(1000);
			exit(0);
		}
		else if (temporary > information.need[informationForCheck.proceedingID][i])
		{
			printf("\n#输入错误#\n错误信息: 申请资源量大于该进程需求量\n");
			Sleep(1000);
			exit(0);
		}
		else
			informationForCheck.need[i] = temporary;
	}
	if (1 == securityCheck())//the request can be satisfied .
	{
		for (int i = 0; i<information.resource; i++)//allocate
		{
			//refresh need
			information.need[informationForCheck.proceedingID][i] = information.need[informationForCheck.proceedingID][i] - informationForCheck.need[i];
			//refresh allocation
			information.allocation[informationForCheck.proceedingID][i] = information.allocation[informationForCheck.proceedingID][i] + informationForCheck.need[i];
			//refresh available
			information.available[i] = information.available[i] - informationForCheck.need[i];
		}
	}
	else
	{
		;//nothing.
	}
}
int securityCheck()
{
	system("cls");
	printf("\n安全性检查\n");
	printf("----------------------------\n");
	struct systemInformation copyInformation = information, temporaryInformation;//to protect original data.

	//STEP ONE:experimental allocate
	for (int i = 0; i<copyInformation.resource; i++)
	{
		//refresh need
		copyInformation.need[informationForCheck.proceedingID][i] = copyInformation.need[informationForCheck.proceedingID][i] - informationForCheck.need[i];
		//refresh allocation
		copyInformation.allocation[informationForCheck.proceedingID][i] = copyInformation.allocation[informationForCheck.proceedingID][i] + informationForCheck.need[i];
		//refresh available
		copyInformation.available[i] = copyInformation.available[i] - informationForCheck.need[i];
	}
	printf("\n\n第一步:试探性分配");

	//temporaryInformation <- information <- copyInformation --- to drawTable
	temporaryInformation = information;
	information = copyInformation;
	drawTable();
	//copyInformation <- information <- temporaryInformation -- return to the original condition.
	copyInformation = information;
	information = temporaryInformation;
	printf("\n[Enter]下一步\n");
	getchar();

	//STEP TWO:to check whether all of proceedings can finish .
	system("cls");
	printf("\n安全性检查\n");
	printf("----------------------------\n");

	printf("\n\n第二步:检测是否所有进程都能够完成.\n");
	int haveUnfinishedProceedingTag = 0;//Are there unfinished proceedings ?
	int changeTag = 0;//whether finishTag has changed.
	int eachSatisfiedTag = 0;//eachSatisfiedTag = resource => changeTag = 1; 
	for (int i = 0; i<copyInformation.proceeding; i++)//scan proceedings for those times.
	{
		//set variables in order
		changeTag = 0;
		eachSatisfiedTag = 0;

		for (int j = 0; j<copyInformation.proceeding; j++)//scan all proceedings each time. 
		{
			if (copyInformation.finish[j] == 0)//this proceeding is unfinished now .
			{
				eachSatisfiedTag = 0;
				//if(need:<=available)
				for (int k = 0; k<copyInformation.resource; k++)
				{
					if (copyInformation.need[j][k] <= copyInformation.available[k])
						eachSatisfiedTag++;
				}
				if (eachSatisfiedTag == copyInformation.resource)//this proceeding can finish.
				{
					copyInformation.finish[j] = 1;//to record its finish .
					changeTag = 1;//finish[] was changed .

					//then refresh copyInformation
					for (int k = 0; k<copyInformation.resource; k++)//retrieve its resource .
					{
						copyInformation.available[k] = copyInformation.available[k] + copyInformation.allocation[j][k];
					}
					break;
				}//if-finish
			}//if
		}//for-eachTime.

		//whether are all proceedings finished ?
		haveUnfinishedProceedingTag = 1;
		for (int k = 0; k<copyInformation.proceeding; k++)//have unfinished proceedings ?
		{
			if (copyInformation.finish[k] == 0)
			{
				haveUnfinishedProceedingTag = 0;//yes
				break;
			}
		}
		if (haveUnfinishedProceedingTag == 0 && changeTag == 0)//have no way to continue running.
		{
			printf("\n无法完成分配!\n");
			getchar();
			return 0;
		}
		else
		{
			//temporaryInformation <- information <- copyInformation --- to drawTable
			temporaryInformation = information;
			information = copyInformation;
			drawTable();
			//copyInformation <- information <- temporaryInformation -- return to the original condition.
			copyInformation = information;
			information = temporaryInformation;

			printf("\n[Enter]继续\n");
			getchar();
		}
	}//for-scan
	system("cls");
	printf("\n所有程序都可以运行完成!\n");
	Sleep(500);
	printf("\n#系统为安全状态,可以分配#");
	Sleep(500);
	printf("\n\n[Enter]完成");
	getchar();
	return 1;
}
#endif