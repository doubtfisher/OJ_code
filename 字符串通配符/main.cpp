//题目：在计算机中，通配符一种特殊语法，广泛应用于文件搜索、数据库、正则表达式等领域。现要求各位实现字符串通配符的算法。
//要求：
//实现如下2个通配符：
//*：匹配0个或以上的字符（字符由英文字母和数字0 - 9组成，不区分大小写。下同）
//？：匹配1个字符


#include <iostream>
#include <string>
using namespace std;

bool IsMatch(const char* s1, const char* s2)
{
	if (*s1 == '\0'&&*s2 == '\0')
		return true;

	if (*s1 == '\0' || *s2 == '\0')
		return false;

	if (*s1 == '?')
	{
		return IsMatch(s1 + 1, s2 + 1);
	}
	else if (*s1 == '*')
	{
		return IsMatch(s1 + 1, s2) || IsMatch(s1 + 1, s2 + 1) || IsMatch(s1, s2 + 1);
	}
	else if (*s1 == *s2)
	{
		return IsMatch(s1 + 1, s2 + 1);
	}

	return false;
}
int main()
{
	string s1;
	string s2;
	while (cin >> s1 >> s2)
	{
		bool ret = IsMatch(s1.c_str(), s2.c_str());
		if (ret)
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}
	return 0;
}