
//��������-100��100�������жϴ�a��b��Ҫ������
�磺
5  8 ��� 2
3 11 ���3
����������£�

//����������Ҫ����a��b����0���������Ҫ����aС��0��bС��0�ĸ������

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
