��Ŀ��
��������N(N>1)���������ĸ����� ��ͬ����������Ҫ�ظ����㡣��120=2*2*2*3*5������5����������

��������:
�����ж���������ݣ�ÿ��������ݵ�������һ��������N��(1<N<10^9)��
�������:
����ÿ�����ݣ����N���������ĸ���


����ʵ�֣�

#include <iostream>
#include <math.h>
using namespace std;


int main()

{

	int n;
	
	while (cin >> n)

	{
		
		int count = 0;
		
		for (int j = 2; j <= sqrt(n); j++)
	
		{

			while (n % j == 0)	
			{

				count++;
	
				n /= j;

				if (n == 1)
	
					break;

			}

		}
		if (n > 1) 

			count++;   //������ѭ��֮���Դ���1������һ��������

		cout << count << endl;

	}

	return 0;

}


