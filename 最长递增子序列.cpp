��Ŀ��
����һ������ΪN�����飬�ҳ�һ����ĵ������������У���һ������������˳�����ң�
���磺����һ������Ϊ6������A{5�� 6�� 7�� 1�� 2�� 8}��������ĵ�������������Ϊ{5��6��7��8}������Ϊ4.

ʵ�ִ������£�
��1������
#include <iostream>
#include <vector>
using namespace std;

int longest_Incsub(vector<int>& v)
{
	int len = 0;
	int size = v.size();
	vector<int> dp(size, 1);//��ų��ȵ�����
	for (int j = 1; j<size; j++)
	{
		for (int i = 0; i<j; i++) 
		{
			if (v[j]>v[i] && dp[j]<dp[i] + 1)//dp[j]<dp[i]+1�����������ʡ�� 
			{  
				dp[j] = dp[i] + 1; //������v[j]��β�����е�����������г���  
			}
		}
		if (dp[j]>len)
			len = dp[j];
	}
	return len;
}

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	cout << longest_Incsub(v) << endl;
	system("pause");
	return 0;
}


