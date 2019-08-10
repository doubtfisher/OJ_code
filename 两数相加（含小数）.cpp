题目：输入两个超长由数字和小数点组成字符串数字，计算其最后结果，
要求：
不损失精度
收尾不出现无意义的0；
不得使用字符意外的函数
输入：两个string
输出：最后两数结果

思路：
1.首先计算小数点位置，小数少的字符串后面补齐0；
2.设置连个迭代器，指向每个字符串的最后一位；
3.迭代器指向的字符对应的数字相加如果大于9，设置进位符为1；
4.循环进行，遇到小数点，原样打印。
5.判断哪个字符先到最开始位置，如果到达开始位置，则只对剩下的字符串和进位信息进行类似处理。

代码实现：
#include<iostream>
#include<string>
using namespace std;

string add1(string& s1, string& s2)
{
	int pos1 = s1.size() - s1.find('.');
	int pos2 = s2.size() - s2.find('.');
	int len = 0;
	if ((pos1 - pos2) > 0)
	{
		len = pos1 - pos2;
		for (int i = 0; i <len; i++)
		{
			s2 += "0";
		}
	}
	else
	{
		len = pos2 - pos1;
		for (int i = 0; i <len; i++)
		{
			s1 += "0";
		}
	}

	string::iterator it1 = s1.end() - 1;
	string::iterator it2 = s2.end() - 1;
	string res;
	int t = 0;
	while (it2 >= s2.begin() && it1 >= s1.begin())
	{
		if ((*it2) == '.' && (*it1) == '.')
		{
			res += '.';
			it2--;
			it1--;
			continue;
		}
		char tmp = ((*it1) - '0' + (*it2) - '0' + t);
		if (tmp <= 9)
		{
			res += to_string(tmp);
			if (t == 1)
				t = 0;
		}
		else if (tmp>9)
		{
			t = 1;
			res += to_string(tmp % 10);
		}
		if (it1 == s1.begin())
		{
			break;
		}
		if (it2 == s2.begin())
		{
			break;
		}
		it2--;
		it1--;
	}
	if (it1 == s1.begin() && it2 != s2.begin())
	{
		it2--;
		while (it2 >= s2.begin())
		{
			if (t == 1)
			{
				int tmp = (*it2 - '0' + t);
				if (tmp > 9)
				{
					t = 1;
					res += to_string(tmp % 10);
				}
				else
				{
					res += to_string(tmp);
					if (t == 1)
						t = 0;
				}
			}
			else
			{
				res += *it2;
			}
			if (it2 == s2.begin())
				break;
			it2--;
		}
	}
	if (it2 == s2.begin() && it1 != s1.begin())
		it1--;
	{
		while (it1 >= s1.begin())
		{
			if (t == 1)
			{
				int tmp = (*it1 - '0' + t);
				if (tmp > 9)
				{
					t = 1;
					res += to_string(tmp % 10);
				}
				else
				{
					res += to_string(tmp);
					if (t == 1)
						t = 0;
				}
			}
			else
			{
				res += *it1;
			}
			if (it1 == s1.begin())
				break;
			it1--;
		}
	}
	reverse(res.begin(), res.end());
	string::iterator it = res.begin();
	while (it != res.end())
	{
		if (*it == '0')
		{
			res.erase(it);
		}
		else
			break;
	}
	it = res.end() - 1;
	while (it != res.begin())
	{
		if (*it == '0')
		{
			res.erase(it);
			it--;
		}
		else
			break;
	}
	return res;
}

int main()
{
	string A, B;
	cin >> A >> B;
	string res = add1(A, B);
	cout << res;
	system("pause");
}


