#include <iostream>
using namespace std;

//��С������ = �����˻�/���Լ��
//���Լ�����㷨��շת�������ֱ������Ϊ0����ʱ�ĳ����������Լ��

int main()
{
    int a,b;
    cin>>a>>b;
    int ret=0;
    int m=a,n=b;
    int c=a%b;
    while(c)
    {
        a=b;
        b=c;
        c=a%b;
    }
    ret=m*n/b;
    cout<<ret<<endl;
}