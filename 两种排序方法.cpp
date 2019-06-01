题目：
考拉有n个字符串字符串，任意两个字符串长度都是不同的。考拉最近学习到有两种字符串的排序方法： 1.根据字符串的字典序排序。例如：
"car" < "carriage" < "cats" < "doggies < "koala"
2.根据字符串的长度排序。例如：
"car" < "cats" < "koala" < "doggies" < "carriage"
考拉想知道自己的这些字符串排列顺序是否满足这两种排序方法，考拉要忙着吃树叶，所以需要你来帮忙验证。

#include <iostream>
#include <string>
#include <vector>
#include <string.h>
using namespace std;

bool IsLexicSort(vector<string> &v)//判断字符串是否是根据字典序排序
{
    for(size_t i=0;i<v.size()-1;i++)
    {
        if(strcmp(v[i].c_str(),v[i+1].c_str())>0)
            return false;
    }
    return true;
}

bool IsLengthSort(vector<string> &v)//判断字符串是否是根据长度排序
{
    for(size_t i=0;i<v.size()-1;i++)
    {
        if(v[i].size()>v[i+1].size())
            return false;
    }
    return true;
}
int main()
{
    int n;
    cin>>n;
    vector<string> v(n);
    for(size_t i=0;i<n;i++)
    {
        cin>>v[i];
    }
    
    bool Length=IsLengthSort(v);
    bool Lexico=IsLexicSort(v);
    if(!Length && Lexico)
    {
        cout<<"lexicographically"<<endl;
    }
    if(Length && !Lexico)
    {
        cout<<"lengths"<<endl;
    }
    if(Length && Lexico)
    {
        cout<<"both"<<endl;
    }
     if(!Length && !Lexico)
    {
        cout<<"none"<<endl;
    }
    return 0;
}