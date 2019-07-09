#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define GOODSNUM 2             //商品的个数
#define GOODSGROUP 2           //优惠组合的个数
int mix_shopping(){
	int mix = 0;                                                //最少花费钱数
	static int goodsPrice[GOODSNUM] = { 0 };                    //每一种商品的价格
	static int goodsGroup[GOODSGROUP][GOODSNUM + 2] = { 0 };    //每一种优惠组合各类商品的个数  GOODSNUM+1 为每一种优惠组合的价钱  GOODSNUM+2 为原价与优惠的差价
	static int shoppingNum[GOODSNUM] = { 0 };                   //要购买的每种商品的数量
	printf("请输入你要购买的每种商品的数量：\n");
	for (int i = 0; i < GOODSNUM; i++){
		scanf("%d", &shoppingNum[i]);
	}
	printf("请输入每种商品的价格：\n");
	for (int i = 0; i < GOODSNUM; i++){
		scanf("%d", &goodsPrice[i]);
	}
	printf("请输入每一种优惠组合的各类商品的个数：\n");
	for (int i = 0; i < GOODSGROUP; i++){
		for (int j = 0; j < GOODSNUM; j++){
			scanf("%d", &goodsGroup[i][j]);
		}
	}
	printf("请输入每一种优惠组合的价钱：\n");
	for (int i = 0; i < GOODSGROUP; i++){
		scanf("%d", &goodsGroup[i][GOODSNUM + 1 - 1]);
	}
	//求出每一种优惠组合与原价的差价
	for (int i = 0; i < GOODSGROUP; i++){
		for (int j = 0; j < GOODSNUM; j++){
			goodsGroup[i][GOODSNUM + 2 -1] += goodsPrice[j] * goodsGroup[i][j];
		}
		goodsGroup[i][GOODSNUM + 2 - 1] = goodsGroup[i][GOODSNUM + 2 - 1] - goodsGroup[i][GOODSNUM + 1 - 1];
	}
	//将优惠的组合由优惠钱的大小排序
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
//计算最少花费的钱数
int mix_sum(int goodsgroup[][GOODSNUM + 2], int shoppingNum[], int goodsPrice[])
{
	    int i = 0;
	    int j = 0;
		int sum = 0;
		int count = 0;
		for (i = 0; i < GOODSGROUP; i++)    //遍历每一种优惠方案
		{
			count = 0;
			for (j = 0; j < GOODSNUM; j++)    //遍历每一种优惠方法所需商品数量是否满足
			{
				if ((shoppingNum[j] < goodsgroup[i][j]))
				{
					count = 1;
					break;
				}
			}
			if (count == 0)
			{
				for (j = 0; j < GOODSNUM; j++)   //如果满足，从总商品数中减去使用优惠政策的商品数
				{
					shoppingNum[j] -= goodsgroup[i][j];
				}
				return mix_sum(goodsgroup, shoppingNum, goodsPrice) + goodsgroup[i][GOODSNUM];   //剩余商品再次进行最低花费计算
			}
		}
		for (i = 0; i < GOODSNUM; i++)
			sum += shoppingNum[i] * goodsPrice[i];
		return sum;    //若不满足，返回最后剩余商品价格总和
	}
int main(){
	printf("最少购物费用为：%d\n", mix_shopping());
	system("pause");
	return 0;
}
