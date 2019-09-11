#include<stdio.h>
#include<stdlib.h>
int lcsLength(char x[],char y[],int b[][6]){
	int m = sizeof(x)-1;
	int n = sizeof(y)-1;
	int c[7][7] = { 0 };
	for (int i = 1; i <= m; i++)
		c[i][0] = 0;
	for (int i = 1; i <= n; i++)
		c[0][i] = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			if (x[i] == y[j]){
				c[i][j] = c[i - 1][j - 1] + 1;
				b[i][j] = 1;
			}
			else if (c[i - 1][j] >= c[i][j - 1]){
				c[i][j] = c[i - 1][j];
				b[i][j] = 2;
			}
			else{
				c[i][j] = c[i][j - 1];
				b[i][j] = 3;
			}
		}
	}
	return c[m][n];
}
void lcs(int i, int j, char x[], int* b){
	if (i == 0 || j == 0){
		return;
	}
	if ((*(b + i) + j) == 1){
		lcs(i - 1, j - 1, x, b);
		puts(x[i]);
	}
	else if ((*(b + i) + j) == 2){
		lcs(i - 1, j, x, b);
	}
	else{
		lcs(i, j - 1, x, b);
	}
}
int main(){

	system("pause");
	return 0;
}