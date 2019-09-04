题目：
求正整数N(N>1)的质因数的个数。 相同的质因数需要重复计算。如120=2*2*2*3*5，共有5个质因数。

输入描述:
可能有多组测试数据，每组测试数据的输入是一个正整数N，(1<N<10^9)。
输出描述:
对于每组数据，输出N的质因数的个数


代码实现：

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

			count++;   //若跳出循环之后仍大于1，则还有一个质因数

		cout << count << endl;

	}

	return 0;

}


