题目：
Fibonacci数列是这样定义的：
F[0] = 0
F[1] = 1
for each i ≥ 2: F[i] = F[i-1] + F[i-2]
因此，Fibonacci数列就形如：0, 1, 1, 2, 3, 5, 8, 13, ...，在Fibonacci数列中的数我们称为Fibonacci数。给你一个N，你想让其变为一个Fibonacci数，每一步你可以把当前数字X变为X-1或者X+1，现在给你一个数N求最少需要多少步可以变为Fibonacci数。


#include <iostream>
#include <algorithm>

using namespace std;

int fib(int n)
{
    int a=0;
    int b=1;
    int c;
    while(n--)
    {
        c=a+b;
        a=b;
        b=c;
    }
    return c;
}

int main()
{
    int N;
    int ret1=0,ret2=0;
    int i=1;
    cin>>N;
   while(fib(i)<N)
   {
       i++;
   }
   ret1=fib(i)-N;
   ret2=N-fib(i-1);
   cout<<min(ret1,ret2)<<endl;
}