题目：
查找两个字符串a,b中的最长公共子串。若有多个，输出在较短串中最先出现的那个。

方法1：
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str1,str2;
    while(cin>>str1>>str2)
    {
        if(str1.size()>str2.size())//确保str2为长的字符串
        {
            swap(str1,str2);
        }
        string ret;
        for(size_t i=0;i<str1.size();i++)//结束条件
        {
            for(size_t j=i;j<str1.size();j++)//往后找子串
            {
                string tmp=str1.substr(i,j-i+1);
                if((int)(str2.find(tmp))<0)//这里一定要强转，因为find如果失败的话，返回的是npos
                    break;
                else if(tmp.size()>ret.size())//不断更新结果
                    ret=tmp;
            }
        }
        cout<<ret<<endl;
    }
    return 0;
}


方法2：
使用动态规划，加一个start标记即可,注意将较短子串最先出现的那个输出。

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    string s1,s2;
   while(cin>>s1>>s2)
   {
        if(s1.size()>s2.size())
            swap(s1,s2);//保持s1存短的字符串
        int len1=s1.size();
        int len2=s2.size();
        int maxlen=0;
        int start=0;//标识最长公共子串的起始位置
        vector<vector<int> > dp(len1+1,vector<int>(len2+1,0));
        int i,j;
        for(i=1;i<=len1;i++)
        {
            for(j=1;j<=len2;j++)
            {
                if(s1[i-1]==s2[j-1])
                    dp[i][j]= dp[i-1][j-1]+1;
                //如果有更长的公共子串，则更新长度
                if(dp[i][j]>maxlen)
                {
                    maxlen=dp[i][j];
                    start=i-maxlen;//以i结尾的最大长度为max，则子串的起始位置为i-manlen
                }
            }
        }
        cout<<s1.substr(start,maxlen)<<endl;
   }
    return 0;
}