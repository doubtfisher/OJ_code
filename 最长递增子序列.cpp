题目：
给定一个长度为N的数组，找出一个最长的单调自增子序列（不一定连续，但是顺序不能乱）
例如：给定一个长度为6的数组A{5， 6， 7， 1， 2， 8}，则其最长的单调递增子序列为{5，6，7，8}，长度为4.

实现代码如下：
（1）动规
#include <iostream>
#include <vector>
using namespace std;

int longest_Incsub(vector<int>& v)
{
	int len = 0;
	int size = v.size();
	vector<int> dp(size, 1);//存放长度的数组
	for (int j = 1; j<size; j++)
	{
		for (int i = 0; i<j; i++) 
		{
			if (v[j]>v[i] && dp[j]<dp[i] + 1)//dp[j]<dp[i]+1这个条件不能省略 
			{  
				dp[j] = dp[i] + 1; //计算以v[j]结尾的序列的最长递增子序列长度  
			}
		}
		if (dp[j]>len)
			len = dp[j];
	}
	return len;
}

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	cout << longest_Incsub(v) << endl;
	system("pause");
	return 0;
}


