//��Ŀ��
//n ֻ��ţ����һ�ţ�ÿ����ţӵ�� ai ��ƻ����������Ҫ������֮��ת��ƻ����
//ʹ�����������ţӵ�е�ƻ��������ͬ��ÿһ�Σ���ֻ�ܴ�һֻ��ţ��������ǡ������ƻ������һ����ţ�ϣ�
//��������Ҫ�ƶ����ٴο���ƽ��ƻ�������������������� -1��

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	int x;
	cin >> n;
	vector<int> v;
	while (cin >> x)
	{
		v.push_back(x);
	}
	int sum = 0;
	for (size_t i = 0; i<v.size(); i++)
	{
		sum += v[i];
	}
	int flag = 1;
	int count = 0;
	if (sum%n == 0)
	{
		int arv = sum / n;
		for (size_t i = 0; i<v.size(); i++)
		{
			if (v[i]>arv)
			{
				if ((v[i] - arv) % 2 == 0)
				{
					count += (v[i] - arv) / 2;
					flag = 1;
				}
				else
				{
					flag = 0;
					break;
				}
			}
		}
	}
	else
	{
		flag = 0;
	}
	if (flag)
		cout << count << endl;
	else
		cout << -1 << endl;
}