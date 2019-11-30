//#include <iostream>
//using namespace std;
//
//int main1()
//{
//	int price = 0;
//	int money = 0;
//	cin >> price;
//
//	if (price <= 100000)
//	{
//		money = price*0.1;
//	}
//	else if (price > 100000 && price <= 200000)
//	{
//		money = 10000 + (price-100000)*0.075;
//	}
//	else if (price > 200000 && price <= 400000)
//	{
//		money = 10000 + 7500 + (price - 200000)*0.05;
//	}
//	else if (price > 400000 && price <= 600000)
//	{
//		money = 10000 + 7500 + 10000 + (price-400000)*0.03;
//	}
//	else if (price > 600000 && price <= 1000000)
//	{
//		money = 10000 + 7500 + 10000 + 6000 + (price-600000)*0.015;
//	}
//	else if (price > 1000000)
//	{
//		money = 10000 + 7500 + 10000 + 6000 + 6000 + (price - 1000000)*0.01;
//	}
//
//	cout << money << endl;
//	system("pause");
//	return 0;
//}