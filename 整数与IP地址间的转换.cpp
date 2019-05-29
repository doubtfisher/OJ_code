//#include <iostream>
//#include <string>
//#include <vector>
//#include <math.h>
//#include <stdlib.h>
//using namespace std;
//
//void convert_8bit_binary(int n, vector<int> &v)//转换为8位的二进制数
//{
//	vector<int> ret;
//	for (size_t i = 0; i<8; i++)
//	{
//		int a = n % 2;
//		ret.push_back(a);
//		n /= 2;
//	}
//	for (int i = 7; i >= 0; i--)
//	{
//		v.push_back(ret[i]);
//	}
//}
//
//void convert_32bit_binary(long long n, vector<int> &v)//转换为32位的二进制数
//{
//	vector<int> vv(32);
//	for (int i = 0; i<32; i++)
//	{
//		int a = n % 2;
//		vv.push_back(a);
//		n /= 2;
//	}
//	for (int i = 31; i >= 0; i--)
//	{
//		v.push_back(vv[i]);
//	}
//}
//
//int main()
//{
//	string ip;
//	long long nums;
//	int pos = 0, len;
//	long long sum = 0;
//	while (cin >> ip)
//	{
//		////输入十进制的数
//		//vector<int> v1;
//		////1.IP地址到整数的转换
//		//for (size_t i = 0; i<ip.size(); i++)
//		//{
//		//	if (ip[i] == '.')
//		//	{
//		//		len = i - pos;
//		//		string str = ip.substr(pos, len);
//		//		int num = atoi(str.c_str());
//		//		v1.push_back(num);
//		//		pos = i + 1;
//		//	}
//		//	else if (i == ip.size() - 1)
//		//	{
//		//		len = i - pos + 1;
//		//		string str = ip.substr(pos, len);
//		//		int num = atoi(str.c_str());
//		//		v1.push_back(num);
//		//	}
//		//}
//
//		//vector<int> temp;
//		//for (size_t i = 0; i<v1.size(); i++)
//		//{
//		//	if (v1[i]<0 || v1[i]>255)
//		//	{
//		//		cout << "ip invaild" << endl;
//		//	}
//		//	else
//		//	{
//		//		convert_8bit_binary(v1[i], temp);
//		//	}
//		//}
//
//		//for (int i = temp.size() - 1, k = 0; i >= 0; i--)
//		//{
//		//	sum += temp[i] * pow(2, k);
//		//	k++;
//		//}
//		//cout << sum << endl;
//
//		cin >> nums;
//		//2.整数到ip地址的转换
//		vector<int> temp1;
//		convert_32bit_binary(nums, temp1);
//
//		vector<int> temp2;
//		vector<int> temp3;
//		for (int i = 0; i<32; i++)
//		{
//			temp2.push_back(temp1[i]);
//			if ((i + 1) % 8 == 0)
//			{
//				int sum1 = 0;
//				for (int i = 0, k = temp2.size() - 1; i<temp2.size(); i++, k--)
//				{
//					sum1 += temp2[i] * pow(2, k);
//				}
//				temp3.push_back(sum1);
//				temp2.clear();
//			}
//		}
//		cout << temp3[0] << "." << temp3[1] << "." << temp3[2] << "." << temp3[3] << endl;
//	}
//	return 0;
//}