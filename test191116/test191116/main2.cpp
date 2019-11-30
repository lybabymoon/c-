#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> change(vector<vector<int>> & ans)
{
	vector<vector<int>> cur(3, vector<int>(3, 0));

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cur[j][i] = ans[i][j];
		}
	}
	return cur;
}
int main2()
{
	vector<vector<int>> ans(3,vector<int>(3,0));

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> ans[i][j];
		}
	}

	ans = change(ans);

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << ans[i][j] <<" ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}