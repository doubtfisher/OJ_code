
//剪花布条

//一块花布条，里面有些图案，另有一块直接可用的小饰条，里面也有一些图案。对于给定的花布条和小饰条，
//计算一下能从花布条中尽可能剪出几块小饰条来呢？每组数据包含两个字符串s, t，分别是成对出现的花布
//条和小饰条，其布条都是用可见ASCII字符表示的，可见的ASCII字符有多少个，布条的花纹也有多少种花样。
//花纹条和小饰条不会超过1000个字符长。


#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s, t;
	while (cin >> s >> t)
	{
		size_t pos = s.find(t, 0);
		int ret = 0;
		while (pos != string::npos)
		{
			ret++;
			pos = s.find(t, pos + t.size());
		}
		cout << ret << endl;
	}
}