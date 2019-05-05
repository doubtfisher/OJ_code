题目：
定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数，时间复杂度应为O（1）

class Solution {
public:
    stack<int> st1,st2;
    void push(int value) 
    {
        st1.push(value);
        if(st2.empty())
        {
            st2.push(value);
        }
        else if(value<=st2.top())
        {
            st2.push(value);
        }
    }

    void pop()
    {
        if(st1.top()==st2.top())
        {
             st2.pop();
        }
        st1.pop();
    }

    int top() 
    {
       return st1.top(); 
    }

    int min() 
    {
       return st2.top(); 
    }
};