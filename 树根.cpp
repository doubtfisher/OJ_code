//��Ŀ��
//��������ͨ����һ�����ĸ���λ�ϵ����ּ������õ�������õ�������һλ������ô�������������������������λ�����߰�������λ�����֣���ô�ٰ���Щ���ּ���������˽�����ȥ��ֱ���õ���һλ��Ϊֹ��
//���磬����24 ��˵����2 ��4 ��ӵõ�6������6 ��һλ�������6 ��24 ��������
//�ٱ���39����3 ��9 �������õ�12������12 ����һλ������˻��ð�1 ��2 �����������õ�3������һ��һλ�������3 ��39 ��������
//���ڸ���һ�����������������������

#include <iostream>
#include <string>
using namespace std;

int IsDataBoot(string s)
{
	int sum = 0;
	for (size_t i = 0; i<s.size(); i++)
	{
		sum = sum + (int)(s[i] - '0');
	}
	return (sum - 1) % 9 + 1;
}

int main()
{

	string s;
	while (cin >> s)
	{
		int ret = 0;
		ret = IsDataBoot(s);
		cout << ret << endl;
	}
}


//#include <iostream>
//using namespace std;
//
//int IsDataBoot(int n)
//{
//	int remainder = n % 10;
//	int tmp = n / 10;
//	int ret = remainder + tmp;
//	while (ret>9)
//	{
//		remainder = ret % 10;
//		tmp = ret / 10;
//		ret = remainder + tmp;
//		n = ret;
//	}
//	if (ret <= 9)
//		return ret;
//
//	return 0;
//}
//
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		int ret = 0;
//		ret = IsDataBoot(n);
//		cout << ret << endl;
//	}
//}