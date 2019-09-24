使用栈实现队列的下列操作：


push(x) -- 将一个元素放入队列的尾部。

pop() -- 从队列首部移除元素。

peek() -- 返回队列首部的元素。

empty() -- 返回队列是否为空。



代码实现：

class MyQueue {
public:
    stack<int> st1;
    stack<int> st2;
    
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        st1.push(x);
       
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(st2.empty())
        {
           while(!st1.empty())
           {
                st2.push(st1.top());
                st1.pop();
           }
        }
        int front=st2.top();
        st2.pop();
        return front;
    }
    
    /** Get the front element. */
    int peek() {
       if(st2.empty())
        {
           while(!st1.empty())
           {
                st2.push(st1.top());
                st1.pop();
           }
        }
        int front=st2.top();
        return front;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return st1.empty()&&st2.empty();
    }
};