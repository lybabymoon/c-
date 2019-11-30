#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main2()
{
	double a, b, c, x1, x2, tmp;
	cin >> a >> b >> c;
	x1 = (-b + sqrt(b*b - 4 * a*c)) / (2 * a);
	x2 = (-b - sqrt(b*b - 4 * a*c)) / (2 * a);
	if (x1<x2)
	{
		tmp = x1;
		x1 = x2;
		x2 = tmp;
	}
	cout << setiosflags(ios::fixed) << setprecision(2) << x1 << " " << x2 << endl;
	return 0;
}