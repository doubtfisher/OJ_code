题目：
输入两个字符串，从第一字符串中删除第二个字符串中所有的字符。例如，输入”They are students.”和”aeiou”，则删除之后的第一个字符串变成”Thy r stdnts.”

方法1：

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    for(int i=0;i<s2.size();i++)//先遍历短的字符串
    {
        for(int j=0;j<s1.size();j++)//再去长字符串中找对应的字符
        {
            if(s2[i]==s1[j])//遇到了，就删除
            {
                s1.erase(j,1);
            }
        }
    }
    cout<<s1<<endl;
}

方法2：

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1;
    string s2;
    getline(cin,s1);
    getline(cin,s2);
    int countArray[256]={0};
    for(int i=0;i<s2.size();i++)// 使用映射思想先统计短字符串中每个字符出现的次数
    {
        countArray[s2[i]]++;
    }
    
    string ret;
    //遍历str1，str1[i]对应数组下标的值如果为0，则表示这个字符在str2中没有出现过，就将他+=到ret。
    for(int i=0;i<s1.size();i++)
    {
        if(countArray[s1[i]]==0)
        {
            ret+=s1[i];
        }
    }
    cout<<ret<<endl;
}