//��Ŀ����һֻ���ӣ��ӳ������3������ÿ���¶���һֻ���ӣ�
//С���ӳ����������º�ÿ��������һֻ���ӣ��������Ӷ���������ÿ���µ���������Ϊ���٣�


#include <iostream>
using namespace std;

int main()
{
	int month;
	while (cin >> month)
	{
		int f = 1;
		int s = 1;
		int ret;
		for (size_t i = 3; i <= month; i++)
		{
			ret = f + s;
			f = s;
			s = ret;
		}
		cout << ret << endl;
	}
}