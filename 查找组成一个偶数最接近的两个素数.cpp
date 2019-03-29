//题目：
//任意一个偶数（大于2）都可以由2个素数组成，组成偶数的2个素数有很多种情况，
//本题目要求输出组成指定偶数的两个素数差值最小的素数对

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