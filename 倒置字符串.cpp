题目：
将一句话的单词进行倒置，标点不倒置。比如 I like beijing. 经过函数后变为：beijing. like I。

#include <iostream>
#include <string.h>
using namespace std;
void reverseStr(char* start,char* end)
{
    while(start!=end)
    {
        char tmp=*end;
       *end=*start;
       *start=tmp;
        end--;
        start++;
    }
}
int main()
{
    char str[1024];
    gets(str);
    char* end=str+strlen(str)-1;
    //1.翻转整个字符串
    reverseStr(str,end);
    //2.翻转每个单词
    char* start=str;
    while(str)
    {
        char* cur=str;
        while(*cur!=' '&&*cur!='\0')
        {
            cur++;
        }
        reverseStr(str,cur-1);
        if(cur!='\0')
            str=cur+1;
        else
            str=cur;
    }
    cout<<start<<endl;
}

方法2：

#include <iostream>
#include <string>
using namespace std;

//利用cin读取字符串时自动会被空格分隔开，再用另一个字符串存储进行逆序输出
int main()
{
    string s1,s2;
    cin>>s1;
    while(cin>>s2)
    {
        s1=s2+' '+s1;
    }
    cout<<s1<<endl;
}