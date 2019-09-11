#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b))
//背包问题
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
	for (i = 1; i <= n; i++)                 //输入每一个物品的重量和价值
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


//0-1背包
int main()
{
	int m[101][1001] = { 0 };              //背包容量为j，可选择的物品为i，i+1.。。。n时的最优解
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
		for (j = 1; j <= size; j++)                    //遍历m[n][size]
		{                                   
			if (j < weight[i])                         //第i个物品的重量小于背包容量为j时
			{
				m[i][j] = m[i - 1][j];                 //看当前值上边的值
			}
			else
			{
				m[i][j] = MAX(m[i - 1][j], m[i - 1][j - weight[i]] + value[i]);     //比较当前值上边的值 和上边一行 第背包大小减去当前物品重量个 + 当前物品价值  哪个 大就是哪个
			}
		}
	}

	printf("%d", m[n][size]);
	system("pause");
	return 0;                                                                                                                                                                            
}