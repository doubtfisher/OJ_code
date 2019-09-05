题目：
将一个整数拆分使其乘积最大。

思路：
最优化问题，尽量都分成3，不足部分就分成2。

对于 n < 4，可以验证其分解成几个正整数的和的乘积是小于 n 的。
对于 n >= 4, 能证明其能分解成几个数的和使得乘积不小于 n。
如果分解成 1 和 n - 1，那么对乘积是没有帮助的，因此，假设 n
分解成 a 和 n - a，2 <= a <= n - 2，那么
     a * (n - a) > =n
即a * (n - a) - n>=0
  =a*n-a*a-n
  = (a - 1) * n - a * a + a - a
  = (a - 1) * (n - a) - a
>= (a - 1) * 2 - a
  = a - 2
>= 0
如果 a, n - a 仍然 >= 4，那么继续分解，直至 a, n - a < 4。因为每次分解都能使乘积
增加，所以最优解必是最终分解结果，也即分解出的数全是 2 或 3 。
（1）
假设 n 是偶数，且分解成 a 个 2 和 b 个 3，即 n = 2 * a + 3 * b，则乘积为 2a * 3b。
注意到 23 < 32 且 2 * 3 = 3 * 2 = 6，所以每 3 个 2 换成 2 个 3 会使乘积更大，因此，
最优方案是分解成 n/6*2 个 3 和 n%6/2 个 2，乘积为 3n/6*2 * 2n%6/2。
（2）
假设 n 是奇数，则一定需要分出一个 3，然后 n - 3 就是偶数。因此最优方案是分解出 
(n-3)/6*2+1 个 3 和 (n-3)%6/2 个 2，乘积为 3(n - 3)/6*2+1 * 2(n-3)%6/2。

代码实现：

#include <iostream>
#include <math.h>

using namespace std;

int GetMax(int n)
{
	int Max, ThreeIndex, TwoIndex;
	if (n < 4)//小于4的话，尽可能让2多一点
	{
		if (n>2)
			return 2;
		return n == 2 ? 1 : 0;
	}
                //大于4，尽可能让3多
	if (n % 2)//当n是奇数的时候
	{
		TwoIndex = ((n - 3) % 6) / 2;//统计2有多少个
		ThreeIndex = (n - 3) / 6 * 2 + 1;//统计3有多少个
		Max = pow(3, ThreeIndex) * pow(2, TwoIndex);
	}
	else//当n是偶数的时候
	{
		TwoIndex = n % 6 / 2;
		ThreeIndex = n / 6 * 2;
		Max = pow(3, ThreeIndex)*pow(2, TwoIndex);
	}
	return Max;
}

int main()
{
	int n;
	while (cin >> n)
	{
		cout << GetMax(n) << endl;
	}
	return 0;
}