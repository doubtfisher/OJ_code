��Ŀ��
����һ���ַ����������һ���㷨���ж����Ƿ�Ϊһ���Ϸ������Ŵ���
����һ���ַ���A�����ĳ���n���뷵��һ��boolֵ�������Ƿ�Ϊһ���Ϸ������Ŵ���
����������"(()())",6    ���أ�true

class Parenthesis {
public:
    bool chkParenthesis(string A, int n) {
       stack<char> st;
        for(size_t i=0;i<A.size();i++)
        {
            if(A[i]=='(')
            {
                st.push(A[i]);
            }
            if(A[i]==')')
            {
                if(st.empty()||st.top()!='(')
                    return false;
                else
                    st.pop();
            }
        }
        if(st.empty())
            return true;
        else
            return false;
    }
};