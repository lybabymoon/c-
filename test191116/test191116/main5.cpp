#include<iostream>
#include<vector>
using namespace std;

int findPeople(vector<int> &ans,int n)
{
	int count = 0;
	int count_num = 0;

	while (1){
		for (int i = 0; i < n; i++)
		{
			if (ans[i] == 0)
				continue;
			++count;
			if (count == 3)
			{
				ans[i] = 0;
				count = 0;
				++count_num;
			}
			if (count_num == n-1)
			{
				for (int i = 0; i < n; i++)
				{
					if (ans[i] == 1)
					{
						return i + 1;
					}
				}
			}
		}
	}
	return 0;
}
int main()
{
	int n = 0;
	cin >> n;
	
	vector<int> ans(n,1);
	
	 cout << findPeople(ans, n) << endl;
	system("pause");
	return 0;

}