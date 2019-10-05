题目：
  给定仅有小写字母组成的字符串数组 A，返回列表中的每个字符串中都显示的全部字符（包括重复字符）组成的列表。例如，如果一个字符在每个字符串中出现 3 次，但不是 4 次，则需要在最终答案中包含该字符 3 次。

你可以按任意顺序返回答案。

?


示例 1：


输入：["bella","label","roller"]

输出：["e","l","l"]

示例 2：


输入：["cool","lock","cook"]

输出：["c","o"]
?


提示：


1 <= A.length <= 100

1 <= A[i].length <= 100

A[i][j] 是小写字母



思路分析：
数组中字符串数量大于等于2个 此题的本质为求一个字符串数组中每个字符串的公共字符（重复多次计数），采用类似动态规划的思想，整体的公共字符必然是某几个字符串的公共字符。 那么整体的公共字符必然是前俩个字符串的公共字符。

实现代码如下：

class Solution {
public:        
    vector<string> str_to_vec(string s)
    {
        vector<string> vs;
        for(auto ch:s)
        {
            string tmp(1,ch);
            vs.push_back(tmp);
        }
        return vs;
    }
    
    string same_substr(const string& s1,const string& s2)
    {
        int num[26]={0};//考虑到重复出现的字符，需要一个数组来记录某个字符最近一次被找到的位置
        string str;
        for(auto ch:s1)//遍历s1
        {
            int index = s2.find(ch,num[ch-'a']);
            if(index<s2.size()&&index>=0)
            {
                str+=ch;
               num[ch-'a']=index+1;
            }
        }
        return str;
    }
    
    vector<string> commonChars(vector<string>& A) {
       vector<string> res;//存放结果的vector
        if(A.size()==1)
            res.push_back(A[0]);
        string tmp=same_substr(A[0],A[1]);
        for(int i=2;i<A.size();i++)
        {
            tmp=same_substr(tmp,A[i]);//求两两相同的子串
        }
        res=str_to_vec(tmp);//把最终找到的公共子串转换为vector<string>的形式
        return res;
    }
};