题目：
牛牛想对一个数做若干次变换，直到这个数只剩下一位数字。变换的规则是：将这个数变成 所有位数上的数字的乘积。比如285经过一次变换后转化成2*8*5=80.问题是，要做多少次变换，使得这个数变成个位数。

代码实现：

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int count=0;
    int tmp=0;
    while(n>9)//保证n不是个位数
    {
        tmp=1;//每次进来tmp都要初始化，否则会被改动
        while(n)//每次要全部转换，直至n为0
        {
            tmp*=n%10;
            n/=10;
        }
        n=tmp;
        count++;
    }
    cout<<count<<endl;
    return 0;
}