#include "design.h"
int mix_shopping(int a,int b){
	int mix = 0;
	int flower = 2;            //花的钱
	int bowel = 5;             //花瓶的钱
	int type1 = 5;             //一的钱
	int type2 = 10;            //二的钱
	int num1 = 0, num2 = 0;    //套餐一和套餐二的数量
	int mix_flower = 0, mix_bowel = 0;   //买花时花的最少的钱和买花瓶时花的最少的钱
	num2 = b / 2;
	if (num2 <= a){
		num1 = (a - num2)/3;
		mix_bowel = type2*num2 + b % 2 * bowel;
		mix_flower = type1*num1 + (a-num2) % 3 * flower;
	}
	else if (num2 > a){
		mix_bowel = type2*a + (b - 2 * a)*bowel;
		mix_flower = 0;
	}
	return mix = mix_bowel + mix_flower;
}