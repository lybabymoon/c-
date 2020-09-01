#include <iostream>
using namespace std;

class A
{
public:
	A()
	{
		cout << "A" << endl;
	}
	
};

class B
{
public:
	static A a;
};
A B::a;
int main()
{
	cout << "main" << endl;
	return 0;
}