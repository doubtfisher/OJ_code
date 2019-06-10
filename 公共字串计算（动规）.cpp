题目：
计算两个字符串的最大公共字串的长度，字符不区分大小写
详细描述：
接口说明
原型：
int getCommonStrLength(char * pFirstStr, char * pSecondStr);
输入参数：
     char * pFirstStr //第一个字符串
     char * pSecondStr//第二个字符串




#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string str1;
    string str2;
    cin>>str1>>str2;
    int len1=str1.size();
    int len2=str2.size();
    //把所有的值初始化为0
    vector<vector<int>> dp(len1,vector<int>(len2,0));
    int max=0;//max赋初值
    for(int i=0;i<len1;i++)
    {
        for(int j=0;j<len2;j++)
        {
            //如果当前结尾的字符相等，则在dp[i-1][j-1]的基础上加1
            if(str1[i]==str2[j])
            {
                if(i>=1&&j>=1)
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else
                    dp[i][j]=1;
            }
            //更新max
            if(dp[i][j]>max)
                max=dp[i][j];
        }
    }
    cout<<max<<endl;
}