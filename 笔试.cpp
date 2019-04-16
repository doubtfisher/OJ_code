
//给定两个-100到100的数，判断从a到b需要几步？
如：
5  8 输出 2
3 11 输出3
具体代码如下：

//分析：不仅要考虑a，b大于0的情况，还要考虑a小于0，b小于0的各种情况

#include <iostream>
using namespace std;

int main()
{
	int m, n;
	cin >> m >> n;

	int count = 0;
	if (m * n > 0)
	{
		if (m < 0 && n < 0)
		{
			m = abs(m);
			n = abs(n);
			cout << m-n << endl;
			system("pause");
			return 0;
		}

		else
		{
			while (m < n)
			{
				m *= 2;
				count++;
			}
			int ret = m - n;
			int tmp = n - m / 2;
			int a = ret > tmp ? tmp : ret;
			count += a;

			if (a == tmp)
				count = count - 1;

			cout << count << endl;
			system("pause");
			return 0;
		}
	}

	if (m <= 0 && n > 0)
	{
		count = -m + 1;
		m = 1;
		while (m < n){
			m *= 2;
			count++;
		}
		int ret = m - n;
		int tmp = n - m / 2;
		int a = ret > tmp ? tmp : ret;
		count += a;

		if (a == tmp)
			count = count - 1;

		cout << count << endl;
		system("pause");
		return 0;
	}
}
