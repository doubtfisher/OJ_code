题目：
给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。


代码实现：

class Solution {
public:
    int N;//定义一个全局变量
    void dfs(int left,int right,string s,vector<string>& ret)
    {
        
        if(right>left)//如果右括号比左括号多，说明无效,则返回
            return;
        if(left>N)//如果左括号数量超过N，则与题意不符，返回
            return;
        if(left==right&&right==N)//如果左右括号都达到了指定数量，则可以将其添加到数组中保存
        {
            ret.push_back(s);
            return;
        }
        //如果以上条件都没有满足，则尝试加入新的左括号和右括号
        dfs(left+1,right,s+"(",ret);
        dfs(left,right+1,s+")",ret);
    }
    
    vector<string> generateParenthesis(int n) {
        N=n;
        if(N<0)
            return {};
        vector<string> ret;
        dfs(0,0,"",ret);
        return ret;
    }
};