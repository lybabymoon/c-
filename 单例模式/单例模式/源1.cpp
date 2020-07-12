//多线程 懒汉模式第一次使用实例对象时创建对象
#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

class Singleton
{
public:
	static Singleton* GetInstance()
	{
		if (nullptr == m_pInstance)
		{
			m_mtx.lock();
			if (nullptr == m_pInstance)
			{
				m_pInstance = new Singleton();
			}
			m_mtx.unlock();
		}

		return m_pInstance;
	}

	class Cgarbo
	{
	public:
		~Cgarbo()
		{
			if (Singleton::m_pInstance)
			{
				delete Singleton::m_pInstance;
			}
		}
	};
	static Cgarbo Garbo;
private:
	Singleton()
	{

	}
	Singleton(const Singleton&);
	Singleton& operator=(const Singleton&);

	static Singleton* m_pInstance;
	static mutex m_mtx;
};
Singleton* Singleton::m_pInstance = nullptr;
Singleton::Cgarbo Garbo;
mutex Singleton::m_mtx;

void func(int n)
{
	cout << Singleton::GetInstance() << endl;
}

int main()
{
	thread t1(func, 10);
	thread t2(func, 10);

	t1.join();
	t2.join();

	cout << Singleton::GetInstance() << endl;
	cout << Singleton::GetInstance() << endl;

	return 0;
}


class A {
	static A* a;
public:
	A* getInstance()
	{
		if (a == nullptr)
		{
			a = new A();
		}
	}
private:
	A() {};
	A(A const&);
	A& operator=(const A&);
};
A* A::a = nullptr;