#include <iostream>
using namespace std;
#include <mutex>
#include <thread>
template <class T>
class Shared_ptr
{
	int* _pRefCount; //引用计数
	T* _ptr; //指向管理资源的指针
	mutex * _pMutex; //互斥锁

private:
	void Release()
	{
		bool deleteflag = false;
		_pMutex->lock();
		if (--(*_pRefCount) == 0)
		{
			delete _ptr;
			delete _pRefCount;
			deleteflag = true;
		}

		_pMutex->unlock();
		if (deleteflag == true)
		{
			delete _pMutex;
		}
	}
public:
	Shared_ptr(T* ptr = NULL)
		:_ptr(ptr)
		,_pRefCount(new int(1))
		,_pMutex(new mutex)
	{}
	~Shared_ptr()
	{}

	Shared_ptr(const Shared_ptr<T>& sp)
		:_ptr(sp._ptr)
		,_pRefCount(sp._pRefCount)
		,_pMutex(sp._pMutex)
	{
		AddRefCount();
	}

	//sp1 = sp2
	Shared_ptr<T>& operator=(const Shared_ptr<T>& sp)
	{
		if (this->_ptr != sp._ptr)
		{
			Release();
			_ptr = sp._ptr;
			_pRefCount = sp._pRefCount;
			_pMutex = sp._pMutex;

			AddRefCount();
		}

		return *this;
	}

	T& operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}
	int UseCount()
	{
		return *_pRefCount;
	}

	T* Get()
	{
		return _ptr;
	}

	void AddRefCount()
	{
		_pMutex->lock();
		++(*_pRefCount);
		_pMutex->unlock();
	}
};

int main()
{
	int a = 1, b = 2, c = 3;
	int* pa = &a;
	int* pb = &b;
	int* pc = &c;
	Shared_ptr<int> sp1(pa);
	Shared_ptr<int> sp2(pa);
	*sp2 = 20;
	
	cout << sp1.UseCount() << endl;
	cout << sp2.UseCount() << endl;
	cout << *sp1 << " " << *sp2<< endl;
	Shared_ptr<int> sp3(pa);

	cout << sp1.UseCount() << endl;
	cout << sp2.UseCount() << endl;
	cout << sp3.UseCount() << endl;

	
	cout << sp1.UseCount() << endl;
	cout << sp2.UseCount() << endl;
	cout << sp3.UseCount() << endl;
	return 0;
}