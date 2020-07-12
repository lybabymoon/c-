//#include <iostream>
//using namespace std;
//
////懒汉模式：
//class Singleton
//{
//	static Singleton* m_instance;
//	
//public:
//	static Singleton* GetInstance()
//	{
//		if (m_instance == nullptr)
//		{
//			m_instance = new Singleton();
//		}
//		return m_instance;
//	}
//
//private:
//	Singleton()
//	{};
//	Singleton(Singleton const&) = delete;
//	Singleton& operator=(Singleton const&) = delete;
//};
//
//Singleton* Singleton::m_instance = nullptr;  //初始化
//
////饿汉模式
//class Singleton2
//{
//	static Singleton2 instance;
//	
//	Singleton2() {};
//	~Singleton2() {};
//	Singleton2(const Singleton2&);
//	Singleton2& operator=(const Singleton2&);
//public:
//	static Singleton2& getInstance()
//	{
//		return instance;
//	}
//};
//
//Singleton2 Singleton2::instance;  //初始化
//int main()
//{
//	
//	return 0;
//}