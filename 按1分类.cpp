按1分类

题目描述：
输入包含T个测试用例，每行为一个测试用例，一个测试用例包含N个数，
按照每个数中的二进制位为1的个数来分类，输出每组数据中可以分为几类。


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