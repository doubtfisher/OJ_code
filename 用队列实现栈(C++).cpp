题目：
用队列实现栈（c++)
使用队列实现栈的下列操作：


push(x) -- 元素 x 入栈

pop() -- 移除栈顶元素

top() -- 获取栈顶元素

empty() -- 返回栈是否为空

代码实现：

class MyStack {
    queue<int> q1;
    queue<int> q2;
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {//插入元素时，要往不为空的队列进行插入
        if(q1.empty())
            q2.push(x);
        else
            q1.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if(q1.empty())
        {
            int sz=q2.size();
            for(int i=0;i<sz-1;i++)
            {
                q1.push(q2.front());
                q2.pop();
            }
            int top=q2.front();//两个队列进行来回倒时，要保证最终始终有一个队列为空
            q2.pop();
            return top;
        }
        else
        {
            int sz=q1.size();
            for(int i=0;i<sz-1;i++)
            {
                q2.push(q1.front());
                q1.pop();
            }
            int top=q1.front();//两个队列进行来回倒时，要保证最终始终有一个队列为空
            q1.pop();
            return top;
        }
        
    }
    
    /** Get the top element. */
    int top() {
        if(q1.empty())
        {
            int sz=q2.size();
            for(int i=0;i<sz-1;i++)
            {
                q1.push(q2.front());
                q2.pop();
            }
            int top=q2.front();
            q1.push(q2.front());
            q2.pop();//永远保证有一个队列为空
            return top;
        }
        else
        {
            int sz=q1.size();
            for(int i=0;i<sz-1;i++)
            {
                q2.push(q1.front());
                q1.pop();
            }
            int top=q1.front();
            q2.push(q1.front());
            q1.pop();//永远保证有一个队列为空
            return top;
        }
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty()&&q2.empty();
    }
};