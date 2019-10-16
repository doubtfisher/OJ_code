��Ŀ��
�ö���ʵ��ջ��c++)
ʹ�ö���ʵ��ջ�����в�����


push(x) -- Ԫ�� x ��ջ

pop() -- �Ƴ�ջ��Ԫ��

top() -- ��ȡջ��Ԫ��

empty() -- ����ջ�Ƿ�Ϊ��

����ʵ�֣�

class MyStack {
    queue<int> q1;
    queue<int> q2;
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {//����Ԫ��ʱ��Ҫ����Ϊ�յĶ��н��в���
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
            int top=q2.front();//�������н������ص�ʱ��Ҫ��֤����ʼ����һ������Ϊ��
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
            int top=q1.front();//�������н������ص�ʱ��Ҫ��֤����ʼ����һ������Ϊ��
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
            q2.pop();//��Զ��֤��һ������Ϊ��
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
            q1.pop();//��Զ��֤��һ������Ϊ��
            return top;
        }
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty()&&q2.empty();
    }
};