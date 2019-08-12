��1����

��Ŀ������
�������T������������ÿ��Ϊһ������������һ��������������N������
����ÿ�����еĶ�����λΪ1�ĸ��������࣬���ÿ�������п��Է�Ϊ���ࡣ


#include <iostream>
#include <vector>
using namespace std;

int CountOf1(int n)
{
	int a = 0;
	while (n)
	{
		++a;
		n = (n - 1) & n;
	}
	return a;
}

int main()
{
	int T;
	while (cin >> T)
	{
		while (T--)
		{
			int N;
			cin >> N;
			vector<int> v(N);
			for (int i = 0; i < N; ++i)
				cin >> v[i];

			vector<int> count(32);
			for (int i = 0; i < N; ++i)
				count[CountOf1(v[i])]++;

			int sum = 0;
			for (int i = 0; i < 32; ++i)
			{
				if (count[i] != 0)
					++sum;
			}
			cout << sum << endl;
		}
	}
	return 0;
}