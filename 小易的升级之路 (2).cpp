��Ŀ��
С�׾���������������Ϸ.��һ��,������һ�������������Ϸ,���Ľ�ɫ�ĳ�ʼ����ֵΪ a.�ڽ�������һ��ʱ����,��������������n������,ÿ������ķ�����Ϊb1,b2,b3...bn. ��������Ĺ��������biС�ڵ���С�׵ĵ�ǰ����ֵc,��ô���������ɴ�ܹ���,�� ��ʹ���Լ�������ֵ����bi;���bi����c,����Ҳ�ܴ�ܹ���,����������ֵֻ������bi ��c�����Լ��.��ô��������,��һϵ�еĶ�����,С�׵���������ֵΪ����?


�������£�
#include <iostream>
#include <vector>
using namespace std;

int CommonDivisor(int a,int b)
{
    int c=a;
    while(c=a%b)
    {
        a=b;
        b=c;
    }
    return b;
}

int main()
{
    int n,a;
    while(cin>>n>>a)
    {
        vector<int> v(n);
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }
        for(int i=0;i<n;i++)
        {
            if(v[i]<=a)
            {
                a+=v[i];
            }
            else
            {
                a+=CommonDivisor(v[i],a);
            }
        }
        cout<<a<<endl;
    }
    return 0;
    
}