��Ŀ��
���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ����Ϊ��ջ�ĵ���˳�򡣼���ѹ��ջ���������־�����ȡ���������1,2,3,4,5��ĳջ��ѹ��˳������4,5,3,2,1�Ǹ�ѹջ���ж�Ӧ��һ���������У���4,3,5,1,2�Ͳ������Ǹ�ѹջ���еĵ������С���ע�⣺���������еĳ�������ȵģ���


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

���ߣ�


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