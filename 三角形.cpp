
//给定三条边，请你判断一下能不能组成一个三角形。
//输入包含多组数据，每组数据包含三个正整数a、b、c（1≤a, b, c≤10 ^ 100）。

#include <iostream>
#include <string>
using namespace std;
#define ADD(x,y) ((x)+(y))
#define MAX(a,b) ((a)>(b))


int main()
{
	double a, b, c;
	while (cin >> a >> b >> c)
	{
		if (MAX(ADD(a, b), c) && MAX(ADD(a, c), b) && MAX(ADD(c, b), a))
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
}