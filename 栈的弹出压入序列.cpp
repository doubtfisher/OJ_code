题目：
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）。


class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> st;
       int pushindex=0,popindex=0;
        while(pushindex<pushV.size())
        {
             st.push(pushV[pushindex++]);
             while(!st.empty()&&st.top()==popV[popindex])
             {
                 st.pop();
                 popindex++;
             }
        }
        if(st.empty())
            return true;
        else
            return false;
    }
};

或者：


class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.size()!=popV.size())
            return false;
        
        stack<int> st;
        int in=0,out=0;
        while(out<popV.size())
        {
            while(st.empty()||st.top()!=popV[out])
            {
                if(in<pushV.size())
                {
                    st.push(pushV[in]);
                    in++;
                }
                else
                {
                    return false;
                }
            }
            st.pop();
            out++;
        }
        return true;
    }
};