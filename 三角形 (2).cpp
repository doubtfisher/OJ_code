��Ŀ��
���������ߣ������ж�һ���ܲ������һ�������Ρ�
��������������ݣ�ÿ�����ݰ�������������a��b��c��1��a, b, c��10^100����

����1����ͳд��

//long double��ȡֵ��Χ:10^-4931---10^4932

#include <iostream>
using namespace std;

int main()
{
    long double a, b, c;
    while (cin >> a >> b >> c)
    {
        if ((a + b > c) && (a + c > b) && (c + b > a))
            cout << "Yes" << endl;
        else 
            cout << "No" << endl;
    }
    return 0;
}

����2��ʹ�ú궨��

#include <iostream>
#include <string>
using namespace std;

#define ADD(x,y) ((x)+(y))
#define BIG(x,y) ((x)>(y))

int main()
{
    double a,b,c;
    while(cin>>a>>b>>c)
    {
        if(BIG(ADD(a,b),c)&& BIG(ADD(a,c),b)&&BIG(ADD(b,c),a))
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
    }
    return 0;
}

����3��ʹ��string���͵Ľ��м���


#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//���ַ�����ʾ����������ӷ��ͱȽϴ�С�ĺ���
string Add(string s1,string s2)//�ַ������
{
    int end1 = s1.size() - 1;
	int end2 = s2.size() - 1;
	int val1 = 0, val2 = 0;
	string ret;
	int next = 0, sumret = 0;
	while (end1 >= 0 || end2 >= 0)
	{
		if (end1 >= 0)
		{
			val1 = s1[end1--] - '0';
		}
		else
		{
			val1 = 0;
		}
		if (end2 >= 0)
		{
			val2 = s2[end2--] - '0';
		}
		else
		{
			val2 = 0;
		}
		sumret = val1 + val2 + next;
		if (sumret>9)
		{
			next = 1;
			sumret -= 10;
		}
		else
		{
			next = 0;
		}
		ret += (sumret + '0');
	}
	if (next == 1)
	{
		ret += '1';
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

bool Greater(string s1,string s2)//�ַ����ȴ�С
{
    int len1=s1.size();
    int len2=s2.size();
    
    if(len1>len2)
        return true;
    else if(len1<len2)
        return false;
    else
        return s1>s2;
}

int main()
{
    string a,b,c;
    while(cin>>a>>b>>c)
    {
        if(Greater(Add(a,b),c)&&Greater(Add(a,c),b)&&Greater(Add(b,c),a))
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
    }
    return 0;
}

