题目：
给定一个字符串，请你找出其中不含有重复字符的最长子串的长度。
示例?1:
输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

示例 2:
输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

思路分析：
记录每次遇到重复之前最长的子串len，并与ret对比，若大于ret就赋值给ret

实现代码：class Solution {
    public int lengthOfLongestSubstring(String s) {
        int ret=0;
        for(int i=0;s[i]!='\0';i++)
        {
            unordered_set<char> str;
            int len=0;
            for(int j=i;s[j]!='\0';j++)
            {
                //在容器中搜索值为k的元素，并返回找到的元素数。因为unordered_set容器不允许重复值，这意味着如果容器中存在具有该值的元素，则该函数实际返回1，否则返回零。
                if(str.count(s[i]))
                    break;
                str.insert(s[i]);
                len++;
            }
            ret=len>ret?len:ret;
        }
        return ret;
    }
}
