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
				   printf("\n[Enter]����\n");
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
				   printf("\n[Enter]����\n");
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
		printf("             ���м��㷨\n");
		printf("    ----------------------------\n");
		printf("\n");
		printf("        (1)---��������\n");
		printf("\n");
		printf("        (2)---ʹ��Ĭ������\n");
		printf("\n");
		if (haveBeenInitializedTag == 1)
		{
			printf("        (3)--����\n");
			printf("\n");
			printf("        (4)--��ʾϵͳ״̬\n");
			printf("\n");
		}
		printf("        (0)---�˳�����\n");
		printf("\n");
		printf("    ----------------------------\n");

		printf("\n��ѡ��:");
		char optionTag = getchar();
		if (optionTag == '0')
		{
			system("cls");
			printf("\n\n\t\t<��ӭ�´�ʹ��>\n\n\t\t");
			Sleep(1000);
			exit(0);
		}
		else if (optionTag == '1' || optionTag == '2')
			return optionTag;
		else if ((optionTag == '3' || optionTag == '4') && haveBeenInitializedTag == 1)
			return optionTag;
		else
		{
			printf("\n#�������#");
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
	printf("������Ϣ\n");
	printf("---------------------------\n");
	printf("\n");

	//input proceeding 
	printf("\n��������̵ĸ���:");
	int temporary = 0;
	scanf("%d", &temporary);
	if (temporary <= 0 || temporary>10)
	{
		printf("\n#�������,�ټ�#\n");
		getchar();
		exit(0);
	}
	else
		information.proceeding = temporary;
	printf("\n#������ P0-p%d ����ʾ\n", temporary);

	//input resource
	printf("\n��������Դ�ĸ���:");
	scanf("%d", &temporary);
	if (temporary <= 0 || temporary>6)
	{
		printf("\n#�������,�ټ�#\n");
		getchar();
		exit(0);
	}
	else
		information.resource = temporary;
	printf("\n#������ A-%c ����ʾ", temporary + 65);

	//input maxResource
	for (int i = 0; i<information.resource; i++)
	{
		printf("\n������%c����Դ����:", i + 65);
		scanf("%d", &temporary);
		if (temporary <= 0)
		{
			printf("\n#�������,�ټ�#");
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
			printf("\n������P%d ��ǰ��ռ��%c ����Դ����Ŀ:", i, j + 65);
			if (temporary <= 0)
			{
				printf("\n#�������,�ټ�#");
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
			printf("\n������P%d ��ǰ����Ҫ%c ����Դ����Ŀ:", i, j + 65);
			if (temporary <= 0)
			{
				printf("\n#�������,�ټ�#");
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
	printf("\n\n��ǰϵͳ״̬:\n\n");

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
			printf("�����");
	}
	printf("\nϵͳʣ��: ");
	for (int i = 0; i<information.resource; i++)
	{
		printf("%c:%d ", i + 65, information.available[i]);
	}
	printf("\n");
}

void financier()
{
	system("cls");
	printf("���м��㷨\n");
	printf("----------------------------\n\n");

	fflush(stdin);//empty  input block.
	printf("������Ҫ������Դ�ĳ���(�� P1): ");
	int temporary = -1;
	char p;
	scanf("%c%d", &p, &temporary);
	if (temporary<0 || temporary >= information.proceeding)
	{
		printf("\n#�������,�ټ�#");
		Sleep(1000);
		exit(0);
	}
	else
		informationForCheck.proceedingID = temporary;

	printf("\n");
	for (int i = 0; i<information.resource; i++)
	{
		printf("������ P%d Ҫ���� %c ����Դ����Ŀ:", informationForCheck.proceedingID, i + 65);
		scanf("%d", &temporary);
		if (temporary < 0)
		{
			printf("\n#�������,�ټ�#");
			Sleep(1000);
			exit(0);
		}
		else if (temporary > information.need[informationForCheck.proceedingID][i])
		{
			printf("\n#�������#\n������Ϣ: ������Դ�����ڸý���������\n");
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
	printf("\n��ȫ�Լ��\n");
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
	printf("\n\n��һ��:��̽�Է���");

	//temporaryInformation <- information <- copyInformation --- to drawTable
	temporaryInformation = information;
	information = copyInformation;
	drawTable();
	//copyInformation <- information <- temporaryInformation -- return to the original condition.
	copyInformation = information;
	information = temporaryInformation;
	printf("\n[Enter]��һ��\n");
	getchar();

	//STEP TWO:to check whether all of proceedings can finish .
	system("cls");
	printf("\n��ȫ�Լ��\n");
	printf("----------------------------\n");

	printf("\n\n�ڶ���:����Ƿ����н��̶��ܹ����.\n");
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
			printf("\n�޷���ɷ���!\n");
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

			printf("\n[Enter]����\n");
			getchar();
		}
	}//for-scan
	system("cls");
	printf("\n���г��򶼿����������!\n");
	Sleep(500);
	printf("\n#ϵͳΪ��ȫ״̬,���Է���#");
	Sleep(500);
	printf("\n\n[Enter]���");
	getchar();
	return 1;
}
#endif