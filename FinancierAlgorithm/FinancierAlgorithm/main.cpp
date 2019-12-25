#include <iostream>
#include <vector>
using namespace std;
// n 资源种类的个数    m 进程个数
void initData(vector<vector<int>> &m_max, vector<int> &m_available, vector<vector<int>> &m_allocation, vector<vector<int>> &m_need,int n, int m)   // 初始化
{
	vector<int> sum(n, 0);

	cout << "请输入各类资源总数" << endl;
	for (int i = 0; i < n; i++)
	{
		int tmp = 0;
		cin >> tmp;
		sum[i] = tmp;
	}
	cout << "请输入T0时刻的 max ：" << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int tmp = 0;
			cin >> tmp;
			m_max[i][j] = tmp;
		}
	}

	cout << "请输入T0时刻的 allocation ：" << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int tmp = 0;
			cin >> tmp;
			m_allocation[i][j] = tmp;
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			m_need[i][j] = m_max[i][j] - m_allocation[i][j];
		}
	}
	m_available = sum;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			m_available[i] -= m_allocation[j][i];
		}
	}

}

int processing_num;       //请求的资源编号
bool finacier(vector<vector<int>> &m_max, vector<int> &m_available, vector<vector<int>> &m_allocation, vector<vector<int>> &m_need, vector<int> &m_request, vector<bool> &finish, vector<int> &security_qu,int n, int m)
{
	processing_num = 0;
	for (int i = 0; i < m; i++)
	{
		finish[i] = false;
	}
	int flag = 0;                    //标记是否可以请求资源
	cout << "请输入你要请求资源的进程编号：" << endl;
	cin >> processing_num;
	cout << "请输入你要请求的资源数目：" << endl;
	for (int i = 0; i < n; i++)
	{
		int tmp = 0;
		cin >> tmp;
		m_request[i] = tmp;
	}

	for (int i = 0; i < n; i++)              //判断是否可以请求资源
	{
		if (m_request[i] != m_need[processing_num][i])
		{
			flag = 0;
			break;
		}
		else if (m_request[i] == m_need[processing_num][i])
		{
			flag = 1;
		}
	}

	if (flag)
	{
		for (int i = 0; i < n; i++)
		{
			m_available[i] = m_available[i] + m_allocation[processing_num][i];
			m_allocation[processing_num][i] = 0;
			m_need[processing_num][i] = 0;
			finish[processing_num] = true;
		}
		security_qu.push_back(processing_num);
		return true;
	}

	for (int i = 0; i < n; i++)
	{
		if (m_request[i] > m_need[processing_num][i])
		{
			cout << "请求资源数大于现在所需的资源数！" << endl;
			return false;
		}

		if (m_request[i] > m_available[i])
		{
			cout << "没有足够的资源！" << endl;
			return false;
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		m_available[i] = m_available[i] - m_request[i];
		m_allocation[processing_num][i] = m_allocation[processing_num][i] + m_request[i];
		m_need[processing_num][i] = m_need[processing_num][i] - m_request[i];
	}

	return true;
}

vector<int> securityCheck(vector<vector<int>> &m_max, vector<int> &m_available, vector<vector<int>> &m_allocation, vector<vector<int>> &m_need, vector<int> &m_request, vector<bool> &finish, vector<int> &security_qu, int n, int m)
{
	vector<int> work = m_available;

	int level = 0;	 //表示执行到第几个进程
	int count = 0;   //记录执行银行家算法时的进程完成个数
	int flag = 0;    //排除finish为真时没进行分配的情况
	while (count<m && level < 5*m)
	{
		if (!finish[level%m])
		{
			
			for (int j = 0; j < n; j++)
			{
				flag = 1;
				if (work[j] >= m_need[level%m][j])
				{
					finish[level%m] = true;
				}
				else
				{
					finish[level%m] = false;
					break;
				}
			}
		}
		if(finish[level%m] && flag)
		{
			count++;
			security_qu.push_back(level%m);
			for (int i = 0; i < n; i++)
			{
				work[i] = work[i] + m_allocation[level%m][i];
			}
		}
		level++;
		flag = 0;
	}

	for (int i = 0; i < m; i++)
	{
		if (!finish[i])
		{
			security_qu.clear();
			break;
		}
	}
	if (security_qu.size()>m)
	{
		int tmp_size = security_qu.size() - m;
		security_qu.erase(security_qu.begin(), security_qu.begin() + tmp_size);
	}
	return security_qu;
}

void outputData(vector<vector<int>> m_max, vector<int> m_available, vector<vector<int>> m_allocation, vector<vector<int>> m_need, vector<int> m_request, int n, int m)
{
	cout << "available:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << m_available[i] << " ";
	}
	cout << endl;
	
	cout << "max:" << endl;
	for (int i = 0; i < m; i++)
	{
		cout << i << ":";
		for (int j = 0; j < n; j++)
		{
			cout << m_max[i][j] <<" ";
		}
		cout << endl;
	}
	cout << endl;

	cout << "allocation:" << endl;
	for (int i = 0; i < m; i++)
	{
		cout << i << ":";
		for (int j = 0; j < n; j++)
		{
			cout << m_allocation[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	cout << "need:" << endl;
	for (int i = 0; i < m; i++)
	{
		cout << i << ":";
		for (int j = 0; j < n; j++)
		{
			cout << m_need[i][j] <<" ";
		}
		cout << endl;
	}
	cout << endl;
}

void welcome()
{
	cout << "|******************************************|" << endl;
	cout << "|******************************************|" << endl;
	cout << "|*****************welcome******************|" << endl;
	cout << "|****************银行家算法****************|" << endl;
	cout << "|**************1.初始化********************|" << endl;
	cout << "|**************2.执行银行家算法************|" << endl;
	cout << "|**************3.安全检查******************|" << endl;
	cout << "|**************4.显示资源情况**************|" << endl;
	cout << "|**************0.退出**********************|" << endl;
	cout << "|******************************************|" << endl;
	cout << "|******************************************|" << endl;
}

void menue()
{
	vector<int> cur;
	int m = 0;    //进程个数
	int n = 0;    //资源种类个数
	cout << "请输入进程的个数" << endl;
	cin >> m;
	cout << "请输入资源种类的个数" << endl;
	cin >> n;
	system("cls");
	vector<vector<int>> m_max(m,vector<int>(n,0));          //每一类资源的最大需求
	vector<vector<int>> m_need(m, vector<int>(n,0));        //每一个进程还需要的资源
	vector<int> m_available(n);     //当前可利用的资源
	vector<vector<int>> m_allocation(m, vector<int>(n,0));  //每一类资源当前已分配的资源
	vector<int> m_request(n);	//
	vector<bool> finish(m + 1, false);
	vector<int> m_work(m,0); 
	vector<int> security_qu;
	
	system("cls");
	int _option;
	
	do{
		system("cls");
		welcome();
		cout << "请输入你要选择的功能" << endl;
		cin >> _option;
		system("cls");
		switch (_option)
		{
		case 1:
			security_qu.clear();
			initData(m_max, m_available, m_allocation, m_need, n, m);
			break;
		case 2:
			if (finacier(m_max, m_available, m_allocation, m_need, m_request, finish, security_qu,n, m))
			{
				cur = securityCheck(m_max, m_available, m_allocation, m_need, m_request,finish, security_qu ,n, m);
				if (cur.size()!=0)
				{
					for (int i = 0; i < cur.size(); i++)
					{
						cout << cur[i];
						if (i < cur.size() - 1)
							cout << "->";
					}
					cout << endl;
				}
			}
			system("pause");
			break;
		case 3:
			cur = securityCheck(m_max, m_available, m_allocation, m_need, m_request, finish, security_qu, n, m);
			if (cur.size()!=0)
			{
				for (int i = 0; i < cur.size(); i++)
				{
					cout << cur[i];
					if (i < cur.size()-1)
					cout << "->";
				}
				cout << endl;
			}
			else
			{
				for (int i = 0; i < n; i++)
				{
					m_available[i] = m_available[i] + m_request[i];
					m_allocation[processing_num][i] = m_allocation[processing_num][i] - m_request[i];
					m_need[processing_num][i] = m_need[processing_num][i] + m_request[i];
				}
				cout << "没有安全序列！" << endl;
			}
			system("pause");
			break;
		case 4:
			outputData(m_max, m_available, m_allocation, m_need, m_request, n, m);
			system("pause");
			break;
		case 0:
			
			cout << "有缘再见" << endl;
			break;
		default:
			
			cout << "输入错误" << endl;
		}
	}
	while (_option != 0);

}


int main()
{
	menue();
	system("pause");
	return 0;
}