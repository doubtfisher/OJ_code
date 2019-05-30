//题目：
//已知从1至n的数字序列，按顺序入栈，每个数字入栈后即可出栈，也可在栈中 停留，
//等待后面的数字入栈出栈后，该数字再出栈，求该数字序列的某出栈序列是否合法？

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