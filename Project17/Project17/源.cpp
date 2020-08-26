#include <iostream>
using namespace std;
class A
{
public:
	virtual void show()
	{
		cout << "A" << endl;
	}
	virtual void printa()
	{
		cout << "A" << endl;
	}
};
class B :public A
{
public:
	void show()
	{
		cout << "B" << endl;
	}
	void printa()
	{
		cout << "B" << endl;
	}
};
int main()
{
	
	A* a = new B();
	
	a->printa();
	a->show();
	return 0;
}