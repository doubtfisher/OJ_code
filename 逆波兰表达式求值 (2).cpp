题目：
根据逆波兰表示法，求表达式的值。

有效的运算符包括?+,?-,?*,?/?。每个运算对象可以是整数，也可以是另一个逆波兰表达式。


示例?1：


输入: ["2", "1", "+", "3", "*"]

输出: 9

解释: ((2 + 1) * 3) = 9


代码实现：
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
         stack<int> st;
        for(int i=0;i<tokens.size();i++)
        {
            string str=tokens[i];
            if(str=="+"||str=="-"||str=="*"||str=="/")
            {
                int right=st.top();
                st.pop();
                int left=st.top();
                st.pop();
                switch(str[0])
                {
                    case '+':
                        st.push(left+right);
                        break;
                    case '-':
                        st.push(left-right);
                        break;
                    case '*':
                        st.push(left*right);
                        break;
                    case '/':
                        st.push(left/right);
                        break;
                    default:
                        break;
                }
            }
            else
            {
                st.push(atoi(str.c_str()));
            }
        }
        return st.top(); 
    }
};