��Ŀ������
ȫ��Ϊ��д��ĸ�ĺϸ�ȫ��ΪСд��Ҳ�ϸ񣬵�һ����д������ȫСд��Ҳ�ϸ����������ϸ�

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
		cout << "�Ե�" << endl;
	else
		cout << "���" << endl;
	if (Is_Qualify(str2))
		cout << "�Ե�" << endl;
	else
		cout << "���" << endl;
	if (Is_Qualify(str3))
		cout << "�Ե�" << endl;
	else
		cout << "���" << endl;
	if (Is_Qualify(str4))
		cout << "�Ե�" << endl;
	else
		cout << "���" << endl;
	if (Is_Qualify(str5))
		cout << "�Ե�" << endl;
	else
		cout << "���" << endl;
	system("pause");
	return 0;
}
