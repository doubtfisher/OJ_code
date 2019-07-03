题目：
找出字符串中第一个只出现一次的字符。



实现如下：
#include <iostream>
#include <string>

using namespace std;
int main()
{
    string s;
    while(cin>>s)
    {
        int count[256]={0};
        for(size_t i=0;i<s.size();i++)
        {
            count[s[i]]++;
        }
        bool findflag=false;
        for(size_t i=0;i<s.size();i++)
        {
            if(count[s[i]]==1)
            {
                cout<<s[i]<<endl;
                findflag=true;
                break;
            }
        }
        if(findflag==false)
            cout<<-1<<endl;
    }
    return 0;
}