//��Ŀ��
//��֪��1��n���������У���˳����ջ��ÿ��������ջ�󼴿ɳ�ջ��Ҳ����ջ�� ͣ����
//�ȴ������������ջ��ջ�󣬸������ٳ�ջ������������е�ĳ��ջ�����Ƿ�Ϸ���

#include <iostream>
#include <queue>
#include <stack>
#include <string>

using namespace std;

int main()
{
	int t;
	while (cin >> t)
	{
		while (t--)
		{
			string push_st;
			cin >> push_st;
			string pop_st;
			cin >> pop_st;

			queue<int> q;
			stack<int> s;
			for (int i = 0; i < pop_st.size(); i++)
			{
				q.push((pop_st[i] - '0'));
			}
			for (int i = 0; i < push_st.size(); i++)
			{
				s.push((push_st[i] - '0'));
				while (!s.empty() && s.top() == q.front())
				{
					s.pop();
					q.pop();
				}
			}

			if (s.empty())
				cout << "Y" << endl;
			else
				cout << "N" << endl;
		}
	}
	system("pause");
	return 0;
}