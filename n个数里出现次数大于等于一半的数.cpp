题目：输入n个整数，输出出现次数大于等于数组长度一半的数。

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    int n;
    while(cin>>n)
    {
        v.push_back(n);
    }
    int data=v[0];
    int time=1;
    for(int i=1;i<v.size();i++)
    {
       if(time==0)
       {
           data=v[i];
           time=1;
       }
        
       if(data==v[i])
       {
            time++;
       }
       else
       {
            time--;
       }
    }
   cout<<data<<endl;
}