��Ŀ��
����һ��ż��������2����������2��������ɣ����ż����2�������кܶ������������ĿҪ��������ָ��ż��������������ֵ��С�������ԡ�



#include <iostream>
using namespace std;

bool IsPrimeNumber(int m)//�ж��Ƿ�Ϊ����
{
    for(int i=2;i<m;i++)
    {
        if(m%i==0)
            return false;
    }
    return true;
}

int main()
{
       int m;
       while(cin>>m)
       {
            int ret=m,ret1=0,ret2=0;
        for(int i=1;i<=m/2;i++)
        {
            if(IsPrimeNumber(i))
            {
                int j=m-i;
                if(IsPrimeNumber(j))
                {
                    int tmp=abs(j-i);
                    if(ret>tmp)
                    {
                        ret=tmp;
                        ret1=i;
                        ret2=j;
                    }
                }
            }
        }
        cout<<ret1<<endl;
        cout<<ret2<<endl;
   }
   return 0;
}