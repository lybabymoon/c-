#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> findMaxTime(vector<int> ans)
{
	vector<int> cur;
	sort(ans.begin(), ans.end());
	//Ê±
	int tmp1 = 10;
	int tmp2 = 7;
	for (int i = 0; i < ans.size(); i++)
	{
		if (ans[i] <= 2)
		{
			tmp1 = ans[i];
			tmp2 = i;
		}
		if (ans[i] > 2)
		{
			break;
		}
	}
	if (tmp2 < 6)
	{
		cur.push_back(tmp1);
		ans.erase(ans.begin() + tmp2);
	}

	tmp2 = 7;
	for (int i = 0; i < ans.size(); i++)
	{
		if (ans[i] < 4)
		{
			tmp1 = ans[i];
			tmp2 = i;
		}
		if (ans[i] >= 4)
		{
			break;
		}
	}
	if (tmp2 < 6)
	{
		cur.push_back(tmp1);
		ans.erase(ans.begin() + tmp2);
	}
	
	//·Ö
	tmp2 = 7;
	for (int i = 0; i < ans.size(); i++)
	{
		if (ans[i] <= 6)
		{
			tmp1 = ans[i];
			tmp2 = i;
		}
		if (ans[i] > 6)
		{
			break;
		}
	}
	if (tmp2 < 6)
	{
		cur.push_back(tmp1);
		ans.erase(ans.begin() + tmp2);
	}

	tmp1 = ans[ans.size() - 1];
	cur.push_back(tmp1);
//Ãë
	tmp1 = ans[ans.size() - 2];
	cur.push_back(tmp1);

	tmp1 = ans[ans.size() -3];
	cur.push_back(tmp1);

	return cur;
}
int main()
{

	vector<int> _time;
	for (int i = 0; i < 6; i++)
	{
		int tmp = 0;
		cin >> tmp;
		_time.push_back(tmp);
	}

	_time = findMaxTime(_time);

	if (_time.size() != 6)
	{
		cout << "None" << endl;
	}
	else
	{
		for (int i = 0; i < 6; i++)
		{
			
			cout << _time[i];
			if (i % 2 != 0 && i%5!=0)
			{
				cout << ":";
			}
		}
	}
	cout << endl;
	system("pause");
	return 0;
}