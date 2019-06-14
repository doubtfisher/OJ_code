题目：
根据逆波兰表示法，求表达式的值。
有效的运算符包括 +, -, *, / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。
说明：
整数除法只保留整数部分。
给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。


题目分析：
       //中缀转后缀，主要目的是分出操作符的优先级，入栈的是操作符
      //后缀主要目的是计算，入的是操作数
      //在中缀表达式中，括号的优先级是最低的（是故意把右括号的优先级设置为最低的，这样的话，之前在括号中的操作符就可以出栈了）
      // 后面的运算符                  前面的运算符
     //中缀的操作符的优先级<= 栈中的操作符的优先级，则前面的运算符就能拿出来计算了（即栈中的操作符可以出栈了）


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        //这里的情况要简单一点，因为题目中的表达式已经全是后缀表达式了，我们只需要计算一下即可
        stack<int> st;
        for(size_t i=0;i<tokens.size();i++)
        {
            string &str=tokens[i];
            if( str=="+"|| str=="-" || str=="*" || str=="/") //是操作数，直接进行运算
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
                }
            }
            else//是操作数，入栈
            {
                st.push(atoi(str.c_str()));
            }
        }
        return st.top();        
    }
};