//题目：
//n 只奶牛坐在一排，每个奶牛拥有 ai 个苹果，现在你要在它们之间转移苹果，
//使得最后所有奶牛拥有的苹果数都相同，每一次，你只能从一只奶牛身上拿走恰好两个苹果到另一个奶牛上，
//问最少需要移动多少次可以平分苹果，如果方案不存在输出 -1。

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	int x;
	cin >> n;
	vector<int> v;
	while (cin >> x)
	{
		v.push_back(x);
	}
	int sum = 0;
	for (size_t i = 0; i<v.size(); i++)
	{
		sum += v[i];
	}
	int flag = 1;
	int count = 0;
	if (sum%n == 0)
	{
		int arv = sum / n;
		for (size_t i = 0; i<v.size(); i++)
		{
			if (v[i]>arv)
			{
				if ((v[i] - arv) % 2 == 0)
				{
					count += (v[i] - arv) / 2;
					flag = 1;
				}
				else
				{
					flag = 0;
					break;
				}
			}
		}
	}
	else
	{
		flag = 0;
	}
	if (flag)
		cout << count << endl;
	else
		cout << -1 << endl;
}