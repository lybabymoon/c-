#include <iostream>
using namespace std;

//class A
//{
//	int c;
//public:
//	int a;
//	int b;
//	virtual void show()
//	{
//		cout << "A" << endl;
//	}
//};
//
//class B :public A
//{
//	int d;
//	int e;
//	void show()
//	{
//		cout << "B" << endl;
//	}
//};

//class A
//{};
//class B:public A
//{};
//
//class C
//{
//public:
//	virtual A* f()
//	{
//		return new A;
//	}
//};
//class D :public C
//{
//public:
//	virtual B* f()
//	{
//		return new B;
//	}
//};

class A
{
public:
	A() {};
	virtual ~A()
	{
		cout << "A" << endl;
	};
};
class B :public A
{
public:
	B()
	{};
	~B()
	{
		cout << "B" << endl;
	}
};
int main()
{
	/*A a;
	a.show();
	A* b = new B();
	b->show();
	cout << sizeof(class A) << endl;
	cout << sizeof(class B) << endl;*/
	A* b = new B;
	delete b;
	return 0;
}