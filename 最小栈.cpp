题目：
设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。

push(x) -- 将元素 x 推入栈中。
pop() -- 删除栈顶的元素。
top() -- 获取栈顶元素。
getMin() -- 检索栈中的最小元素。




class MinStack {
public:
    
    stack<int> st;
    stack<int> minst;
    
    MinStack() {
        
    }
    
    void push(int x) {
        st.push(x);
        if(minst.empty()||x<=minst.top())
        {
            minst.push(x);
        }
    }
    
    void pop() {
        if(st.top()==minst.top())
        {
            minst.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minst.top();
    }
};
