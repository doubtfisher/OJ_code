#include <iostream>
using namespace std;

//最小公倍数 = 两数乘积/最大公约数
//最大公约数的算法：辗转相除法，直到余数为0，此时的除数就是最大公约数

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