#include<iostream>
#include<string>
using namespace std;

string starNums(string & s1)
{
	string s2;
	for (int i = 0; i < s1.size(); i++)
	{
		if (s1[i] == '*')
		{
			s2.push_back(s1[i]);
		}
	}

	for (int i = 0; i < s1.size(); i++)
	{
		if (s1[i] != '*'&& s1[i] != ' ')
		{
			s2.push_back(s1[i]);
		}
	}

	return s2;
}
int main3()
{
	string str;
	string str2;
	int count = 0;
	getline(cin, str);
	str2 = starNums(str);

	for (int i = 0; i < str2.size(); i++)
	{
		if (str2[i] == '*')
		{
			count++;
		}
	}

	cout << str2 << endl;
	cout << count << endl;

	system("pause");
	return 0;
}