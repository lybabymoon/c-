#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string change(string s)
{
	string s2;
	char tmp = 'a';
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'u' || s[i] == 'o')
			s2.push_back(s[i]);
	}

	for (int i = 0; i < s2.size()-1; i++)
	{
		for (int j = 0; j < s2.size() - i -1; j++)
		{
			if (s2[j] > s2[j + 1])
			{
				char tmp = s2[j];
				s2[j] = s2[j+1];
				s2[j + 1] = tmp;
			}
		}
	}

	return s2;
}

int main1()
{
	string s;
	cin >> s;
	cout << change(s);
	system("pause");
	return 0;
}