题目：
给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。


代码实现：

class Solution {
public:
vector<string> ans;
int N;
    
void dfs(int l,int r,string has){
    if(r>l)return;
    if(l > N)return;
    if(l == r&& r == N){
        ans.push_back(has);return;
    }
    dfs(l+1,r,has + "(");
    dfs(l,r+1,has + ")");
}
    
vector<string> generateParenthesis(int n){
    N=n;if(!N)return {};
    dfs(0,0,"");
    return ans;
}
};