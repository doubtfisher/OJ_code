��Ŀ��
Fibonacci��������������ģ�
F[0] = 0
F[1] = 1
for each i �� 2: F[i] = F[i-1] + F[i-2]
��ˣ�Fibonacci���о����磺0, 1, 1, 2, 3, 5, 8, 13, ...����Fibonacci�����е������ǳ�ΪFibonacci��������һ��N�����������Ϊһ��Fibonacci����ÿһ������԰ѵ�ǰ����X��ΪX-1����X+1�����ڸ���һ����N��������Ҫ���ٲ����Ա�ΪFibonacci����


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