#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1;
	string s2;
	int sum1 = 1;
	int sum2 = 1;
	cin >> s1;
	cin >> s2;

	for (int i = 0; i < s1.size(); i++)
	{
		sum1 *= (s1[i] - '@');
	}

	for (int i = 0; i < s2.size(); i++)
	{
		sum2 *= (s2[i] - '@');
	}

	sum1 = sum1 % 47;
	sum2 = sum2 % 47;


	if (sum1 == sum2)
	{
		cout << "GO"<< endl;
	}
	else
	{
		cout << "STAY"  << endl;
	}

	return 0;
}