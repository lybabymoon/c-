#include <iostream>
using namespace std;

class A
{
protected:
	int a;
	void showA()
	{
		cout << a << endl;
	}
};

class B :protected A
{
	
};

class C :protected B
{
public:
	void showC()
	{
		a = 4;
		cout << a << endl;
	}
};

int main()
{
	A a;
	a.showA();
	return 0;
}