题目：
任意一个偶数（大于2）都可以由2个素数组成，组成偶数的2个素数有很多种情况，本题目要求输出组成指定偶数的两个素数差值最小的素数对。



#include <iostream>
using namespace std;

bool IsPrimeNumber(int m)//判断是否为素数
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