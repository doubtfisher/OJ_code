//题目：有一只兔子，从出生后第3个月起每个月都生一只兔子，
//小兔子长到第三个月后每个月又生一只兔子，假如兔子都不死，问每个月的兔子总数为多少？


#include <iostream>
using namespace std;

int main()
{
	int month;
	while (cin >> month)
	{
		int f = 1;
		int s = 1;
		int ret;
		for (size_t i = 3; i <= month; i++)
		{
			ret = f + s;
			f = s;
			s = ret;
		}
		cout << ret << endl;
	}
}