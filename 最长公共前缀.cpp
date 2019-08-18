题目：
编写一个函数来查找字符串数组中的最长公共前缀。如果不存在公共前缀，返回空字符串 ""。

示例?1:


输入: ["flower","flow","flight"]

输出: "fl"

示例?2:


输入: ["dog","racecar","car"]

输出: ""

解释: 输入不存在公共前缀。



思路分析：
找到最短字符串，以它的长度为基准，从所有字符串的第一个字符开始对比，若都一样，ans加上该字符，若不一样，返回

代码实现：
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        if(strs.empty())
            return ans;
        
         //1.找到最小的字符串
        int n=strs.size();
        string min=strs[0];
        for(int  i=0;i<n;i++)
        {
            if(strs[i].size()<min.size())
            {
                min=strs[i];
            }
        }
        //2.用最小的那个字符串挨着遍历,从第一个字符开始对比，若都一样，ans加上该字符
        int m=min.size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(min[i]!=strs[j][i])
                    return ans;               
            }
            ans+=min[i];
        }
        return ans;
    }
};