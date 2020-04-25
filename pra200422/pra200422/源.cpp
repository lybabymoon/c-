#include <iostream>
using namespace std;
class ClxBase
{
	int a;
	char b;
	char g;
	char l;
	char y;
	char i;
public:
	ClxBase()
	{};
	 ~ClxBase()
	{
		cout << "A" << endl;
	}
	virtual void todo () = 0
	{
		cout << "todoB" << endl;
	}

	void dosomething()
	{

	}
};

class ClxA :public ClxBase
{
public:
	ClxA()
	{}
	~ClxA()
	{
		cout << "b" << endl;
	}

	void todo()override
	{
		cout << "todoa" << endl;
	}
};
int main()
{
	ClxA* p = new ClxA;
	//ClxBase* q = new ClxA;
	//p->todo();
	//q->todo();
	p->todo();
	cout << sizeof(ClxBase) << endl;
	delete p;
	return 0;
}