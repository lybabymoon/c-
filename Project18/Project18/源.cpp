#include <iostream>
using namespace std;

//class A
//{
//	int c;
//public:
//	int a;
//protected:
//	int b;
//
//};
//
//class B :private A
//{
//public:
//	void show()
//	{
//		b = 2;
//		cout << b << endl;
//	}
//};

int main1()
{
	/*B b;
	b.show();
	cout << sizeof(b);*/

	union {
		int a;
		char b;
	} i;
	i.b = '1';
	

	cout << i.a << endl;
	cout << i.b << endl;
	return 0;
}