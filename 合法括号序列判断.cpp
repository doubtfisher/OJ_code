题目：
对于一个字符串，请设计一个算法，判断其是否为一个合法的括号串。
给定一个字符串A和它的长度n，请返回一个bool值代表它是否为一个合法的括号串。
测试样例："(()())",6    返回：true

class Parenthesis {
public:
    bool chkParenthesis(string A, int n) {
       stack<char> st;
        for(size_t i=0;i<A.size();i++)
        {
            if(A[i]=='(')
            {
                st.push(A[i]);
            }
            if(A[i]==')')
            {
                if(st.empty()||st.top()!='(')
                    return false;
                else
                    st.pop();
            }
        }
        if(st.empty())
            return true;
        else
            return false;
    }
};