��Ŀ��
����һ�����飬���ĵ�?i ��Ԫ����һ֧������Ʊ�� i ��ļ۸�

��������ֻ�������һ�ʽ��ף������������һ֧��Ʊ�������һ���㷨�����������ܻ�ȡ���������

ע���㲻���������Ʊǰ������Ʊ��



ʾ�� 1:


����: [7,1,5,3,6,4]

���: 5

����: �ڵ� 2 �죨��Ʊ�۸� = 1����ʱ�����룬�ڵ� 5 �죨��Ʊ�۸� = 6����ʱ��������������� = 6-1 = 5 ��
    ע���������� 7-1 = 6, ��Ϊ�����۸���Ҫ��������۸�


ʾ�� 2:


����: [7,6,4,3,1]

���: 0

����: �����������, û�н������, �����������Ϊ 0��



����ʵ�֣�
��1���������
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size=prices.size();
        int max=0;//�������
        for(int i=0;i<size;i++)
        {
            int tmp=0;
            for(int j=i+1;j<size;j++)
            {
                if(prices[i]<prices[j])
                {
                    tmp=prices[j]-prices[i];
                    max=max<tmp?tmp:max;
                }
            }
        }
        return max;
    }
};


��2����ջ��

class Solution {
public:
    int maxProfit(vector<int>& prices) {      
        int size=prices.size();
        int max=0;//�������
        stack<int> st;
        st.push(10000);//�����һ�����ֲ�����Ļ������в������ݷŲ���ȥ����ʵ10000���Գ����ģ�������
        
        for(int i=0;i<size;i++)
        {
            if(prices[i]<st.top())//ջ�����Ƚ�����������������ջ����������ļ۸����������
                st.push(prices[i]);
            else
            {
                int tmp=prices[i]-st.top();
                max=max<tmp?tmp:max;   
            }
                        
        }
        return max;        
    }
};