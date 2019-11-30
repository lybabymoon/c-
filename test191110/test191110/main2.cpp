#include<iostream>
#include<vector>
using namespace std;
int findElement(vector<int> A, int n, int x) {
	int flag = 0;
	int left1 = 0;
	int left2 = 0;
	int right1 = 0;
	int right2 = 0;
	int mid = 0;
	for (int i = 1; i < n-1; i++)
	{
		if (((A[i]>A[i - 1]) && (A[i] > A[i + 1])) ||
			((A[i] < A[i - 1]) && (A[i] < A[i + 1]))){
			flag = i;
		}
	}
	left1 = 0;
	right1 = flag - 1;
	left2 = flag;
	right2 = A.size() - 1;
	if (A[flag] <= x)
	{
		while (left1 <= right1)
		{
			mid = (left1 + right1) / 2;
			if (x>A[mid])
				left1 = mid + 1;
			if (x < A[mid])
				right1 = mid;
			if (x == A[mid])
				return A[mid];
		}
	}
	else
	{
		while (left2 <= right2)
		{
			mid = (left2 + right2) / 2;
			if (x>A[mid])
				left2 = mid + 1;
			if (x < A[mid])
				right2 = mid;
			if (x == A[mid])
				return A[mid];
		}
	}
	return 0;
}

int main()
{
	vector<int> A = { 6, 1, 2, 3, 4, 5 };
	int n = 6;
	int x = 6;
	cout << findElement(A, n, x);
	system("pause");
	return 0;
}