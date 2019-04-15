


//题目：NowCoder每天要处理许多邮件，但他并不是在收件人列表中，有时候只是被抄送。他认为这些抄//送的邮件重要性比自己在收件人列表里的邮件低，因此他要过滤掉这些次要的邮件，优先处理重要的邮件//，现在给你一串抄送列表，请你判断目标用户是否在抄送列表中。



//输入描述:
输入有多组数据，每组数据有两行。


//第一行抄送列表，姓名之间用一个逗号隔开。如果姓名中包含空格或逗号，则姓名包含在双引号里。总长//度不超过512个字符。


//第二行只包含一个姓名，是待查找的用户的名字（姓名要完全匹配）。长度不超过16个字符。




//输出描述:
如果第二行的名字出现在收件人列表中，则输出“Ignore”，表示这封邮件不重要；否则，输出//“Important!”，表示这封邮件需要被优先处理。

#include <iostream>
#include <iostream>
using namespace std;

int main()
{
    string s1,s2;
    while(getline(cin,s1))
    {
          getline(cin,s2);
          bool flag=false;
        for(size_t i=0;i<s1.size();i++)//去遍历长的字符串
        {
            string tmp;
            //第一个字符是‘”’
            if(s1[i]=='"')
            {
                i++;
               while(i<s1.size()&&s1[i]!='"')//当没有走到下一个‘”’时，都是正常字符
               {
                   tmp+=s1[i];
                   i++;
               }
                if(tmp==s2)//判断是否一致
                {
                    flag=true;
                    break;
                }
            }
            else
            {
                 while(i<s1.size()&&s1[i]!=',')
               {
                   tmp+=s1[i];
                   i++;
               }
                if(tmp==s2)
                {
                    flag=true;
                     break;
                }
           }
        }
        if(flag)
        {
            cout<<"Ignore"<<endl;
        }
        else
        {
            cout<<"Important!"<<endl;
        }
    }
}