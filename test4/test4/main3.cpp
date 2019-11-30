#include <iostream>
#include <vector>
using namespace std;

int main3()
{
	vector<int> ans;
	int tmp;
	while (cin >> tmp)
	{
		if (tmp == -1)
		{
			break;
		}
		else
		{
			ans.push_back(tmp);
		}
	}

	tmp = ans[0];
	for (int i = 1; i < ans.size(); i++)
	{
		if (ans[i]>tmp)
		{
			tmp = ans[i];
		}
	}

	cout << tmp << endl;
	system("pause");
	return 0;
}