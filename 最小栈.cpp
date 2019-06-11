��Ŀ��
���һ��֧�� push��pop��top �����������ڳ���ʱ���ڼ�������СԪ�ص�ջ��

push(x) -- ��Ԫ�� x ����ջ�С�
pop() -- ɾ��ջ����Ԫ�ء�
top() -- ��ȡջ��Ԫ�ء�
getMin() -- ����ջ�е���СԪ�ء�




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
