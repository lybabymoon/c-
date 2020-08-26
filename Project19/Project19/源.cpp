#include <iostream>
using namespace std;

class Base
{
	
public:
	int x;
	Base(int b) :x(b)
	{};
	void show()
	{
		cout << x << endl;
	}
};

class Derived :public Base
{
	int y;
public:
	Derived(int d):Base(d),y(d)
	{}
	void show()
	{
		cout << y << endl;
	}
};
int main()
{
	Base b(2);
	Derived d(3);
	b.show();
	d.show();
	Base* p = &d;
	cout << p->x << endl;
	p->show();
	b.show();
	return 0;
}