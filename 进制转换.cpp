题目：
给定一个十进制数M，以及需要转换的进制数N。将十进制数M转化为N进制数。



解题思路：N进制数，每个进制位的值分别是X0*N^0，X1*N^1, X2*N^2.....，X0，其中X1，X2就是这些进制位的值，就是进行取模，余数便是当前进制的位的值，通过除掉进制数，进入下一个进制位的计算。


#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string str="0123456789ABCDEF";
    string s;
    int m,n;
    cin>>m>>n;
    bool flag=false;
  // 如果是负数，则转成正数，并标记一下
    if(m<0)
    {
        m=-m;
        flag=true;
    }
 // 按进制换算成对应的字符添加到s
    while(m)
    {
        s+=str[m%n];
        m/=n;
    }
    
    if(flag)
        s+='-';
    reverse(s.begin(),s.end());
    cout<<s<<endl;
}