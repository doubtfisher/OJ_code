//��Ŀ��Fibonacci��������������ģ�
//F[0] = 0
//F[1] = 1
//for each i �� 2: F[i] = F[i - 1] + F[i - 2]
//��ˣ�Fibonacci���о����磺0, 1, 1, 2, 3, 5, 8, 13, ...����Fibonacci�����е������ǳ�ΪFibonacci��������һ��N�����������Ϊһ��Fibonacci����ÿһ������԰ѵ�ǰ����X��ΪX - 1����X + 1�����ڸ���һ����N��������Ҫ���ٲ����Ա�ΪFibonacci����


#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int f = 0;
	int s = 1;
	int fib, d1, d2;
	int N;
	cin >> N;
	while (1)
	{
		fib = f + s;
		f = s;
		s = fib;
		if (fib <= N)
		{
			d1 = N - fib;
		}
		else
		{
			d2 = fib - N;
			break;
		}
	}
	cout << min(d1, d2) << endl;
}