//��Ŀ��
//С�׾���������������Ϸ.��һ��, ������һ�������������Ϸ, 
//���Ľ�ɫ�ĳ�ʼ����ֵΪ a.�ڽ�������һ��ʱ����, ��������������n������, 
//ÿ������ķ�����Ϊb1, b2, b3...bn.��������Ĺ��������biС�ڵ���С�׵ĵ�ǰ����ֵc,
//��ô���������ɴ�ܹ���, �� ��ʹ���Լ�������ֵ����bi; ���bi����c, 
//����Ҳ�ܴ�ܹ���, ����������ֵֻ������bi ��c�����Լ��.��ô��������, ��һϵ�еĶ�����, 
//С�׵���������ֵΪ���� ?

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int CommonDivisor(int a, int b)
{

	int c = a%b;
	while (c)
	{
		a = b;
		b = c;
		c = a%b;
	}
	return b;
}
int main()
{
	int n, a;
	int b;
	vector<int> v;
	while (cin >> n >> a)
	{
		while (n--)
		{
			cin >> b;
			v.push_back(b);
		}
		for (size_t i = 0; i<v.size(); i++)
		{
			if (v[i] <= a)
			{
				a += v[i];
			}
			else
			{
				a += CommonDivisor(v[i], a);
			}
		}
		cout << a << endl;
		v.clear();
	}
}