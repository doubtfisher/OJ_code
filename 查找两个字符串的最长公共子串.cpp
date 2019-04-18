//题目：
//查找两个字符串a,b中的最长公共子串。若有多个，输出在较短串中最先出现的那个。
//输入描述:输入两个字符串
//输出描述:返回重复出现的字符
//示例1
//输入：abcdefghijklmnop
            abcsafjklmnopqrstuvw
//输出：jklmnop



#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1,s2;
    while(cin>>s1>>s2)
    {
        if(s1.size()<s2.size())
        {
        swap(s1,s2);
        }
        string ret;
        for(size_t  i=0;i<s2.size();i++)
        {
           for(size_t  j=i;j<s2.size();j++)
           {
               string tmp=s2.substr(i,j-i+1);
               if(int(s1.find(tmp))<0)
               {
                   break;
               }
               else if(ret.size()<tmp.size())
               {
                  ret=tmp;
               }
           }
        }
        cout<<ret<<endl;
     }
      return 0;
}
