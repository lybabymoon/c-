#include <iostream>
using namespace std;

int main()
{
	int b = 5;
	int c = 4;
	int* a = &b;
	int* d = &c;
	auto_ptr<int> au(a);
	auto_ptr<int> au1(d);
	au1 = au;
	unique_ptr<int> un(a);
	unique_ptr<int> un1(d);
	shared_ptr<int> sh(a);
	shared_ptr<int> sh2(a);
	sh2 = sh;
	cout << *sh << endl;
	return 0;
}