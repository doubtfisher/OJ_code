��Ŀ��
�����沨����ʾ��������ʽ��ֵ��

��Ч�����������?+,?-,?*,?/?��ÿ��������������������Ҳ��������һ���沨�����ʽ��


ʾ��?1��


����: ["2", "1", "+", "3", "*"]

���: 9

����: ((2 + 1) * 3) = 9


����ʵ�֣�
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
         stack<int> st;
        for(int i=0;i<tokens.size();i++)
        {
            string str=tokens[i];
            if(str=="+"||str=="-"||str=="*"||str=="/")
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
                    default:
                        break;
                }
            }
            else
            {
                st.push(atoi(str.c_str()));
            }
        }
        return st.top(); 
    }
};