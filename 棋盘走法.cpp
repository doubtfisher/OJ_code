��Ŀ��
����n x m�����̸��ӣ�nΪ����ĸ�������mΪ����ĸ����������Ÿ��Ա�Ե�ߴ����Ͻ��ߵ����½ǣ��ܹ��ж������߷���Ҫ�����߻�ͷ·������ֻ�����Һ������ߣ���������������ߡ�


#include <iostream>
using namespace std;

int Step(int n,int m)
{
    if((n==1&&m>=1)||(n>=1&&m==1))
        return n+m;
    
   return Step(n,m-1)+Step(n-1,m);
}

int main()
{
    int n,m;
    while(cin>>n>>m)
    {
       cout<<Step(n,m)<<endl;
    }
    
    return 0;
}