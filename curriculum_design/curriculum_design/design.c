#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define GOODSNUM 2             //��Ʒ�ĸ���
#define GOODSGROUP 2           //�Ż���ϵĸ���
int mix_shopping(){
	int mix = 0;                                                //���ٻ���Ǯ��
	static int goodsPrice[GOODSNUM] = { 0 };                    //ÿһ����Ʒ�ļ۸�
	static int goodsGroup[GOODSGROUP][GOODSNUM + 2] = { 0 };    //ÿһ���Ż���ϸ�����Ʒ�ĸ���  GOODSNUM+1 Ϊÿһ���Ż���ϵļ�Ǯ  GOODSNUM+2 Ϊԭ�����ŻݵĲ��
	static int shoppingNum[GOODSNUM] = { 0 };                   //Ҫ�����ÿ����Ʒ������
	printf("��������Ҫ�����ÿ����Ʒ��������\n");
	for (int i = 0; i < GOODSNUM; i++){
		scanf("%d", &shoppingNum[i]);
	}
	printf("������ÿ����Ʒ�ļ۸�\n");
	for (int i = 0; i < GOODSNUM; i++){
		scanf("%d", &goodsPrice[i]);
	}
	printf("������ÿһ���Ż���ϵĸ�����Ʒ�ĸ�����\n");
	for (int i = 0; i < GOODSGROUP; i++){
		for (int j = 0; j < GOODSNUM; j++){
			scanf("%d", &goodsGroup[i][j]);
		}
	}
	printf("������ÿһ���Ż���ϵļ�Ǯ��\n");
	for (int i = 0; i < GOODSGROUP; i++){
		scanf("%d", &goodsGroup[i][GOODSNUM + 1 - 1]);
	}
	//���ÿһ���Ż������ԭ�۵Ĳ��
	for (int i = 0; i < GOODSGROUP; i++){
		for (int j = 0; j < GOODSNUM; j++){
			goodsGroup[i][GOODSNUM + 2 -1] += goodsPrice[j] * goodsGroup[i][j];
		}
		goodsGroup[i][GOODSNUM + 2 - 1] = goodsGroup[i][GOODSNUM + 2 - 1] - goodsGroup[i][GOODSNUM + 1 - 1];
	}
	//���Żݵ�������Ż�Ǯ�Ĵ�С����
	for (int i = 0; i < GOODSGROUP -1; i++){
		for (int j = 0; j < GOODSGROUP - i - 1; j++){
			int tmp = 0;
			if (goodsGroup[j][GOODSNUM + 2 - 1] < goodsGroup[j + 1][GOODSNUM + 2 - 1]){
				for (int y = 0; y < GOODSNUM + 2; y++){
					tmp = goodsGroup[j][y];
					goodsGroup[j][y] = goodsGroup[j + 1][y];
					goodsGroup[j + 1][y] = tmp;
				}
			}
		}
	}
	//
	mix = mix_sum(goodsGroup, shoppingNum, goodsPrice);
	return mix;

}
//�������ٻ��ѵ�Ǯ��
int mix_sum(int goodsgroup[][GOODSNUM + 2], int shoppingNum[], int goodsPrice[])
{
	    int i = 0;
	    int j = 0;
		int sum = 0;
		int count = 0;
		for (i = 0; i < GOODSGROUP; i++)    //����ÿһ���Żݷ���
		{
			count = 0;
			for (j = 0; j < GOODSNUM; j++)    //����ÿһ���Żݷ���������Ʒ�����Ƿ�����
			{
				if ((shoppingNum[j] < goodsgroup[i][j]))
				{
					count = 1;
					break;
				}
			}
			if (count == 0)
			{
				for (j = 0; j < GOODSNUM; j++)   //������㣬������Ʒ���м�ȥʹ���Ż����ߵ���Ʒ��
				{
					shoppingNum[j] -= goodsgroup[i][j];
				}
				return mix_sum(goodsgroup, shoppingNum, goodsPrice) + goodsgroup[i][GOODSNUM];   //ʣ����Ʒ�ٴν�����ͻ��Ѽ���
			}
		}
		for (i = 0; i < GOODSNUM; i++)
			sum += shoppingNum[i] * goodsPrice[i];
		return sum;    //�������㣬�������ʣ����Ʒ�۸��ܺ�
	}
int main(){
	printf("���ٹ������Ϊ��%d\n", mix_shopping());
	system("pause");
	return 0;
}
