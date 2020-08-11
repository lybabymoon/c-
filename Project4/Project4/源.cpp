#include <iostream>
using namespace std;
class A
{
public:
	int m_a;

	A(int i = 0) :
		m_a(i) {}

	virtual void func() {}
};

class B : public A
{
public:
	int m_b;

	B(int i = 0, int j = 0) :
		A(j),
		m_b(i)
	{}
};
int main()
{
	double d = 1.33;
	int i = static_cast<int>(d);
	char j = static_cast<char>(d);
	double x = static_cast<double>(i);
	/*A a(5);
	B b(3, 4);*/
	/*A* pa = static_cast<A*>(&b);
	B* pb = static_cast<B*>(pa);*/

	/*A* pa = dynamic_cast<A*>(&b);
	B* pb = dynamic_cast<B*>(pa);*/

	//cout << pa->m_a << endl;
	//cout << pb->m_b << endl;
	int* pa = &i;
	cout << pa << endl;
	int b = reinterpret_cast<int>(pa);
	cout << b << endl;
	int* pb = reinterpret_cast<int*>(b);
	cout << *pb << endl;
	return 0;
}