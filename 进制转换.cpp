��Ŀ��
����һ��ʮ������M���Լ���Ҫת���Ľ�����N����ʮ������Mת��ΪN��������



����˼·��N��������ÿ������λ��ֵ�ֱ���X0*N^0��X1*N^1, X2*N^2.....��X0������X1��X2������Щ����λ��ֵ�����ǽ���ȡģ���������ǵ�ǰ���Ƶ�λ��ֵ��ͨ��������������������һ������λ�ļ��㡣


#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string str="0123456789ABCDEF";
    string s;
    int m,n;
    cin>>m>>n;
    bool flag=false;
  // ����Ǹ�������ת�������������һ��
    if(m<0)
    {
        m=-m;
        flag=true;
    }
 // �����ƻ���ɶ�Ӧ���ַ���ӵ�s
    while(m)
    {
        s+=str[m%n];
        m/=n;
    }
    
    if(flag)
        s+='-';
    reverse(s.begin(),s.end());
    cout<<s<<endl;
}