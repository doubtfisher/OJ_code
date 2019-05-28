//题目：给定一个24进制的数，把它转换为10进制的数


//#include <iostream>
//#include <string>
//#include <vector>
//#include <math.h>
//using namespace std;
//
//int main()
//{
//	int t;
//	cin >> t;
//	int ret = 0;
//	vector<string> v(t);
//	string str = "0123456789abcdefghijklmn";
//	for (int i = 0; i < t; i++)
//	{
//		cin >> v[i];
//	}
//
//	for (int i = 0; i < t; i++)
//	{
//		for (int j = v[i].size() - 1; j >= 0; j--)
//		{
//			for (int k = 0; k < str.size(); k++)
//			{
//				if (v[i][j] == str[k])
//				{
//					ret += k*pow(24, v[i].size()-1-j);
//				}
//			}
//		}
//		cout << ret << endl;
//		ret = 0;
//	}
//	system("pause");
//	return 0;
//}