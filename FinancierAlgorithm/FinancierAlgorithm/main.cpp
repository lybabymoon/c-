#include <iostream>
#include <vector>
using namespace std;
// n ��Դ����ĸ���    m ���̸���
void initData(vector<vector<int>> &m_max, vector<int> &m_available, vector<vector<int>> &m_allocation, vector<vector<int>> &m_need,int n, int m)   // ��ʼ��
{
	vector<int> sum(n, 0);

	cout << "�����������Դ����" << endl;
	for (int i = 0; i < n; i++)
	{
		int tmp = 0;
		cin >> tmp;
		sum[i] = tmp;
	}
	cout << "������T0ʱ�̵� max ��" << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int tmp = 0;
			cin >> tmp;
			m_max[i][j] = tmp;
		}
	}

	cout << "������T0ʱ�̵� allocation ��" << endl;
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

int processing_num;       //�������Դ���
bool finacier(vector<vector<int>> &m_max, vector<int> &m_available, vector<vector<int>> &m_allocation, vector<vector<int>> &m_need, vector<int> &m_request, vector<bool> &finish, vector<int> &security_qu,int n, int m)
{
	processing_num = 0;
	for (int i = 0; i < m; i++)
	{
		finish[i] = false;
	}
	int flag = 0;                    //����Ƿ����������Դ
	cout << "��������Ҫ������Դ�Ľ��̱�ţ�" << endl;
	cin >> processing_num;
	cout << "��������Ҫ�������Դ��Ŀ��" << endl;
	for (int i = 0; i < n; i++)
	{
		int tmp = 0;
		cin >> tmp;
		m_request[i] = tmp;
	}

	for (int i = 0; i < n; i++)              //�ж��Ƿ����������Դ
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
			cout << "������Դ�����������������Դ����" << endl;
			return false;
		}

		if (m_request[i] > m_available[i])
		{
			cout << "û���㹻����Դ��" << endl;
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

	int level = 0;	 //��ʾִ�е��ڼ�������
	int count = 0;   //��¼ִ�����м��㷨ʱ�Ľ�����ɸ���
	int flag = 0;    //�ų�finishΪ��ʱû���з�������
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
	cout << "|****************���м��㷨****************|" << endl;
	cout << "|**************1.��ʼ��********************|" << endl;
	cout << "|**************2.ִ�����м��㷨************|" << endl;
	cout << "|**************3.��ȫ���******************|" << endl;
	cout << "|**************4.��ʾ��Դ���**************|" << endl;
	cout << "|**************0.�˳�**********************|" << endl;
	cout << "|******************************************|" << endl;
	cout << "|******************************************|" << endl;
}

void menue()
{
	vector<int> cur;
	int m = 0;    //���̸���
	int n = 0;    //��Դ�������
	cout << "��������̵ĸ���" << endl;
	cin >> m;
	cout << "��������Դ����ĸ���" << endl;
	cin >> n;
	system("cls");
	vector<vector<int>> m_max(m,vector<int>(n,0));          //ÿһ����Դ���������
	vector<vector<int>> m_need(m, vector<int>(n,0));        //ÿһ�����̻���Ҫ����Դ
	vector<int> m_available(n);     //��ǰ�����õ���Դ
	vector<vector<int>> m_allocation(m, vector<int>(n,0));  //ÿһ����Դ��ǰ�ѷ������Դ
	vector<int> m_request(n);	//
	vector<bool> finish(m + 1, false);
	vector<int> m_work(m,0); 
	vector<int> security_qu;
	
	system("cls");
	int _option;
	
	do{
		system("cls");
		welcome();
		cout << "��������Ҫѡ��Ĺ���" << endl;
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
				cout << "û�а�ȫ���У�" << endl;
			}
			system("pause");
			break;
		case 4:
			outputData(m_max, m_available, m_allocation, m_need, m_request, n, m);
			system("pause");
			break;
		case 0:
			
			cout << "��Ե�ټ�" << endl;
			break;
		default:
			
			cout << "�������" << endl;
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