//��Ŀ��
//����һ��ż��������2����������2��������ɣ����ż����2�������кܶ��������
//����ĿҪ��������ָ��ż��������������ֵ��С��������

#include <iostream>
using namespace std;
bool Is_PrimeNumber(int n)
{
	for (int i = 2; i<n; i++)
	{
		if (n%i == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int n;
	while (cin >> n)
	{
		int min = n;
		int ret1 = 0;
		int ret2 = 0;
		for (int i = 1; i <= n / 2; i++)
		{
			if (Is_PrimeNumber(i))
			{
				int j = n - i;
				if (Is_PrimeNumber(j))
				{
					int ret = abs(j - i);
					if (ret<min)
					{
						min = ret;
						ret1 = i;
						ret2 = j;
					}
				}
			}
		}
		cout << ret1 << endl;
		cout << ret2 << endl;
	}
}