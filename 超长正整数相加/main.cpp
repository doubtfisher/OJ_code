//题目：请设计一个算法完成两个超长正整数的加法。

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string GetLongString(string s1, string s2)
{
	int end1 = s1.size() - 1;
	int end2 = s2.size() - 1;
	int val1 = 0, val2 = 0;
	string ret;
	int next = 0, sumret = 0;
	while (end1 >= 0 || end2 >= 0)
	{
		if (end1 >= 0)
		{
			val1 = s1[end1--] - '0';
		}
		else
		{
			val1 = 0;
		}
		if (end2 >= 0)
		{
			val2 = s2[end2--] - '0';
		}
		else
		{
			val2 = 0;
		}
		sumret = val1 + val2 + next;
		if (sumret>9)
		{
			next = 1;
			sumret -= 10;
		}
		else
		{
			next = 0;
		}
		ret += (sumret + '0');
	}
	if (next == 1)
	{
		ret += '1';
	}
	reverse(ret.begin(), ret.end());
	return ret;
}
int main()
{
	string s1;
	string s2;
	while (cin >> s1 >> s2)
	{
		cout << GetLongString(s1, s2).c_str() << endl;
	}

}