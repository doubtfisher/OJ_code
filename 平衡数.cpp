题目：

牛牛在研究他自己独创的平衡数，平衡数的定义是：将一个数分成左右两部分，分别成为两个新的数。
左右部分必须满足以下两点：
1，左边和右边至少存在一位。
2，左边的数每一位相乘如果等于右边的数每一位相乘，则这个数称为平衡数。

例如：1221这个数，分成12和21的话，1*2=2*1，则称1221为平衡数，再例如：1236这个数，可以分成123和1*2*3=6，所以1236也是平衡数。而1234无论怎样分也不满足平衡数。


#include <iostream>
#include <vector>
using namespace std;

bool IsBalance(int n)
{
    if(n<10)
        return false;
    
    //1.计算该数有几位
    int count=0;
    int tmp=n;
    while(tmp!=0)
    {
        tmp/=10;
        count++;
    }
    //2.把给定的数由低位到高位依次放入vector中
    vector<int> v;
    while(n!=0)
    {
        v.push_back(n%10);
        n/=10;
    }
   
    //3.双层循环遍历vector，判断左右两边乘积是否相等
    bool flag=false;
    int left_mul=1;
    for(int i=0;i<count-1;i++)
    {
        left_mul*=v[i];//左边乘积结果
        int right_mul=1;
        for(int j=i+1;j<count;j++)
        {
            right_mul*=v[j];//右边乘积结果
        }
        if(left_mul==right_mul)
        {
            flag=true;
            break;
        }
    }
    if(flag)
        return true;
    else
        return false;
}

int main()
{
    int n;
    while(cin>>n)
    {
         if(IsBalance(n))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
   return 0;
}