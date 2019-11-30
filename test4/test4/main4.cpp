#include<iostream>
using namespace std;
int main4()
{
	double m, n, sum;
	sum = 0;
	cin >> m >> n;
	for (int i = 0; i<n; i++)
	{
		sum += m;
		m = m / 2;
		sum += m;
	}
	sum -= m;
	printf("%.2f %.2f", m, sum);
	return 0;
}

