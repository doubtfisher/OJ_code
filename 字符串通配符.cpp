题目：
问题描述：在计算机中，通配符一种特殊语法，广泛应用于文件搜索、数据库、正则表达式等领域。现要求各位实现字符串通配符的算法。
要求：
实现如下2个通配符：
*：匹配0个或以上的字符（字符由英文字母和数字0-9组成，不区分大小写。下同）
？：匹配1个字符

输入：
通配符表达式；
一组字符串。

输出：
返回匹配的结果，正确输出true，错误输出false



#include <iostream>
#include <string>
using namespace std;

bool Match(const char* pattern,const char* str)
{
    if(*pattern=='\0'&&*str=='\0')
        return true;
    if(*pattern=='\0'||*str=='\0')
        return false;
    
    if(*pattern=='?')
        return Match(pattern+1,str+1);
    else if(*pattern=='*')
        return Match(pattern+1,str)//遇到*号，匹配0个(str不挪动)
        ||Match(pattern+1,str+1)//匹配1个（两者都向前挪动一个字符）
        ||Match(pattern,str+1);//或匹配多个(str向前挪动一个字符)
    else if(*pattern==*str)
        return Match(pattern+1,str+1);//如果当前字符相等，匹配下一个字符
    
    return false;
}

int main()
{
    string pattern;
    string str;
    while(cin>>pattern>>str)
    {
         bool ret=Match(pattern.c_str(),str.c_str());
        if(ret)
            cout<<"true"<<endl;
        else
            cout<<"false"<<endl;
    }
    return 0;
}