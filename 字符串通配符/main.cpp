//��Ŀ���ڼ�����У�ͨ���һ�������﷨���㷺Ӧ�����ļ����������ݿ⡢������ʽ��������Ҫ���λʵ���ַ���ͨ������㷨��
//Ҫ��
//ʵ������2��ͨ�����
//*��ƥ��0�������ϵ��ַ����ַ���Ӣ����ĸ������0 - 9��ɣ������ִ�Сд����ͬ��
//����ƥ��1���ַ�


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