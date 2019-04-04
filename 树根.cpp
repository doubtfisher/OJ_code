//题目：
//数根可以通过把一个数的各个位上的数字加起来得到。如果得到的数是一位数，那么这个数就是数根；如果结果是两位数或者包括更多位的数字，那么再把这些数字加起来。如此进行下去，直到得到是一位数为止。
//比如，对于24 来说，把2 和4 相加得到6，由于6 是一位数，因此6 是24 的数根。
//再比如39，把3 和9 加起来得到12，由于12 不是一位数，因此还得把1 和2 加起来，最后得到3，这是一个一位数，因此3 是39 的数根。
//现在给你一个正整数，输出它的数根。

#include <iostream>
#include <string>
using namespace std;

int IsDataBoot(string s)
{
	int sum = 0;
	for (size_t i = 0; i<s.size(); i++)
	{
		sum = sum + (int)(s[i] - '0');
	}
	return (sum - 1) % 9 + 1;
}

int main()
{

	string s;
	while (cin >> s)
	{
		int ret = 0;
		ret = IsDataBoot(s);
		cout << ret << endl;
	}
}


//#include <iostream>
//using namespace std;
//
//int IsDataBoot(int n)
//{
//	int remainder = n % 10;
//	int tmp = n / 10;
//	int ret = remainder + tmp;
//	while (ret>9)
//	{
//		remainder = ret % 10;
//		tmp = ret / 10;
//		ret = remainder + tmp;
//		n = ret;
//	}
//	if (ret <= 9)
//		return ret;
//
//	return 0;
//}
//
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		int ret = 0;
//		ret = IsDataBoot(n);
//		cout << ret << endl;
//	}
//}