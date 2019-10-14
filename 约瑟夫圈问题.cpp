题目：
N个人围成一圈，从第一个人开始按顺序报数并编号1,2,3，……N，然后开始从第一个人转圈报数，凡是报到3的退出圈子。则剩下的最后一个人编号是多少。


代码实现：
#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

int main()
{
	int n, m;
	//  输入描述的是最后为0结束
	while ((cin >> n >> m) && !(n == 0 && m == 0))
	{
		vector<int> vt(n);
		for (int i = 0; i < n; i++)
			vt[i] = i + 1;
		int a = n; //  标记剩下的
		int b = 0; //  标记报数m
		while (a > 1)
		{
			for (int i = 0; i < n; i++)
			{
				if (vt[i] == 0)
					continue;
				else
					b++;

				if (b == m)     //  报数达到m的时候置为0
				{
					vt[i] = 0;
					b = 0;
					a--;
				}
			}
		}
		for (auto e : vt)
		{
			if (e != 0)
				cout << e << endl;
		}
	}
	system("pause");
	return 0;
}