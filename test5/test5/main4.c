/*#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

void f(int a[30][30], int b[30][30], int n) {
	int i, j, c[30][30], k;
	for (i = 0; i < 30; i++)
	for (j = 0; j < 30; j++) {
		c[i][j] = 0;
	}
	for (i = 0; i < n; i++)
	for (j = 0; j < n; j++) {
		for (k = 0; k < n; k++)
			c[i][j] += b[i][k] * a[k][j];
	}
	for (i = 0; i < n; i++)
	for (j = 0; j < n; j++) {
		b[i][j] = c[i][j];
	}
}

void main4() {
	int a[30][30], b[30][30], i, j, m, n;
	for (i = 0; i < 30; i++)
	for (j = 0; j < 30; j++) {
		a[i][j] = 0;
		b[i][j] = 0;
	}
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++)
	for (j = 0; j < n; j++) {
		scanf("%d", &a[i][j]);
		b[i][j] = a[i][j];
	}
	for (i = 1; i < m; i++)
		f(a, b, n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%d", b[i][j]);
			if (j != n - 1)
			{
				printf(" ");
			}
		}
		printf("\n");
	}

	system("pause");
}*/
