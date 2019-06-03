题目：
计算n x m的棋盘格子（n为横向的格子数，m为竖向的格子数）沿着各自边缘线从左上角走到右下角，总共有多少种走法，要求不能走回头路，即：只能往右和往下走，不能往左和往上走。


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