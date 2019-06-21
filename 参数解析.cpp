题目：
在命令行输入如下命令：
xcopy /s c:\ d:\，
各个参数如下： 
参数1：命令字xcopy 
参数2：字符串/s
参数3：字符串c:\
参数4: 字符串d:\
请编写一个参数解析程序，实现将命令行各个参数解析出来。
解析规则： 
1.参数分隔符为空格 
2.对于用“”包含起来的参数，如果中间有空格，不能解析为多个参数。比如在命令行输入xcopy /s “C:\program files” “d:\”时，参数仍然是4个，第3个参数应该是字符串C:\program files，而不是C:\program，注意输出参数时，需要将“”去掉，引号不存在嵌套情况。
3.参数不定长 
4.输入由用例保证，不会出现不符合要求的输入 。



#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    getline(cin,str);
    //1.首先计算参数的个数
    int count=0;
    for(size_t i=0;i<str.size();i++)
    {
        if(str[i]==' ')
            count++;
        if(str[i]=='"')
        {
            i++;
            while(str[i]!='"')
            {
              i++;
            }
        }
    }
    cout<<count+1<<endl;
    //用flag表示是否包含双引号，0表示有双引号
    //双引号中的空格要打印出来
    //用异或改变flag的值，两个双引号可以使flag复原
    int flag=0;//0表示没有双引号，1表示有双引号
    for(size_t i=0;i<str.size();i++)
    {
        //如果是双引号，则flag通过异或置为1，下一次再遇到双引号，flag又置为0
        if(str[i]=='"')
            flag^=1;
        //不是双引号，也不是空格
        if(str[i]!=' '&&str[i]!='"')
            cout<<str[i];
        //双引号中的空格要打印
        if(str[i]==' '&&flag==1)
            cout<<str[i];
        //双引号以外的空格，不打印
        if(str[i]==' '&&flag==0)
            cout<<endl;
    }
    return 0;
}