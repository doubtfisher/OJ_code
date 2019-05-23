题目：
写出一个程序，接受一个由字母和数字组成的字符串，和一个字符，然后输出输入字符串中含有该字符的个数。不区分大小写。

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    cin>>str;
    char ch;
    cin>>ch;
    int count=0;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]==ch||str[i]==ch-32)
        {
            count++;
        }
    }
    cout<<count<<endl;
}