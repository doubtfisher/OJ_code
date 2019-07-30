问题：
NowCoder号称自己已经记住了1-100000之间所有的斐波那契数。
为了考验他，我们随便出一个数n，让他说出第n个斐波那契数。当然，斐波那契数会很大。因此，如果第n个斐波那契数不到6位，则说出该数；否则只说出最后6位。

实现代码：
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int fib[100001];
    fib[0]=1;
    fib[1]=1;
    //提前计算斐波那契数列，并且只保留6位
    for(int i=2;i<=100000;i++)
    {
        fib[i]=fib[i-1]+fib[i-2];
        fib[i]=fib[i]%1000000;//由于是相加，所以只要后六位不影响下一个数的结果
    }
    int n;
    while(cin>>n)
    {
        if(n<29)
            printf("%d\n",fib[n]);
        else
            printf("%06d\n",fib[n]);
    }
    return 0;
}
