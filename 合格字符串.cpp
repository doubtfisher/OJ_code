题目描述：
全部为大写字母的合格，全部为小写的也合格，第一个大写，后面全小写的也合格，其它均不合格。

#include <iostream>
#include <string>
using namespace std;

bool Is_Large(const char ch)
{
	if (ch <= 'z' && ch >= 'a')
		return false;
	return true;
}

bool Is_Qualify(const string& str)
{
	if (Is_Large(str[0]))
	{
		if (Is_Large(str[1]))
		{
			for (size_t i = 1; i < str.size(); ++i)
				if (Is_Large(str[i]) != Is_Large(str[i - 1]))
					return false;
			return true;
		}
		else
		{
			for (size_t i = 2; i < str.size(); ++i)
				if (Is_Large(str[i]) != Is_Large(str[i - 1]))
					return false;
			return true;
		}
	}
	else
	{
		for (size_t i = 1; i < str.size(); ++i)
			if (Is_Large(str[i]) != Is_Large(str[i - 1]))
				return false;
		return true;
	}
}

int main()
{
	string str1, str2, str3, str4, str5;
	str1 = "BiliBili";
	str2 = "BBBBBBBBBBBBB";
	str3 = "Bbbbbbbbbbbbb";
	str4 = "vvvvvvvvvvvvv";
	str5 = "vBvvvvv";
	if (Is_Qualify(str1))
		cout << "对的" << endl;
	else
		cout << "错的" << endl;
	if (Is_Qualify(str2))
		cout << "对的" << endl;
	else
		cout << "错的" << endl;
	if (Is_Qualify(str3))
		cout << "对的" << endl;
	else
		cout << "错的" << endl;
	if (Is_Qualify(str4))
		cout << "对的" << endl;
	else
		cout << "错的" << endl;
	if (Is_Qualify(str5))
		cout << "对的" << endl;
	else
		cout << "错的" << endl;
	system("pause");
	return 0;
}
