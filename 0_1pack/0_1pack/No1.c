#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b))
//��������
int main1()
{
	int data[1001] = { 0 };
	int size, n;
	int weight[101] = { 0 };
	int value[101] = { 0 };
	int i, j;
	printf("Please input size and number:\n");
	scanf("%d%d", &size, &n);
	printf("Please input weight and value:\n");
	for (i = 1; i <= n; i++)                 //����ÿһ����Ʒ�������ͼ�ֵ
	{
		scanf("%d%d", weight + i, value + i);
	}

	for (i = 1; i <= n; i++)
	{
		//for (j = size; j >= weight[i] ; j--)
		for (j = weight[i]; j <= size; j++)
		{
			data[j] = MAX(data[j], data[j - weight[i]] + value[i]);
		}
	}

	printf("%d", data[size]);
	system("pause");
	return 0;
}


//0-1����
int main()
{
	int m[101][1001] = { 0 };              //��������Ϊj����ѡ�����ƷΪi��i+1.������nʱ�����Ž�
	int size, n;
	int weight[101] = { 0 };
	int value[101] = { 0 };
	int i, j;
	printf("Please input size and number:\n");
	scanf("%d%d", &size, &n);
	
	for (i = 1; i <= n; i++)
	{
		printf("Please input the %d weight and the %d value:\n", i, i);
		scanf("%d%d", weight + i, value + i);
	}

	for (i = 1; i <= n; i++)                        
	{
		for (j = 1; j <= size; j++)                    //����m[n][size]
		{                                   
			if (j < weight[i])                         //��i����Ʒ������С�ڱ�������Ϊjʱ
			{
				m[i][j] = m[i - 1][j];                 //����ǰֵ�ϱߵ�ֵ
			}
			else
			{
				m[i][j] = MAX(m[i - 1][j], m[i - 1][j - weight[i]] + value[i]);     //�Ƚϵ�ǰֵ�ϱߵ�ֵ ���ϱ�һ�� �ڱ�����С��ȥ��ǰ��Ʒ������ + ��ǰ��Ʒ��ֵ  �ĸ� ������ĸ�
			}
		}
	}

	printf("%d", m[n][size]);
	system("pause");
	return 0;                                                                                                                                                                            
}