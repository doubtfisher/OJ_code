��Ŀ��
N����Χ��һȦ���ӵ�һ���˿�ʼ��˳���������1,2,3������N��Ȼ��ʼ�ӵ�һ����תȦ���������Ǳ���3���˳�Ȧ�ӡ���ʣ�µ����һ���˱���Ƕ��١�


����ʵ�֣�
#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

int main()
{
	int n, m;
	//  ���������������Ϊ0����
	while ((cin >> n >> m) && !(n == 0 && m == 0))
	{
		vector<int> vt(n);
		for (int i = 0; i < n; i++)
			vt[i] = i + 1;
		int a = n; //  ���ʣ�µ�
		int b = 0; //  ��Ǳ���m
		while (a > 1)
		{
			for (int i = 0; i < n; i++)
			{
				if (vt[i] == 0)
					continue;
				else
					b++;

				if (b == m)     //  �����ﵽm��ʱ����Ϊ0
				{
					vt[i] = 0;
					b = 0;
					a--;
				}
			}
		}
		for (auto e : vt)
		{
			if (e != 0)
				cout << e << endl;
		}
	}
	system("pause");
	return 0;
}