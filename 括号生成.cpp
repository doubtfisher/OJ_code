��Ŀ��
���� n �����������ŵĶ���������д��һ��������ʹ���ܹ��������п��ܵĲ�����Ч��������ϡ�


����ʵ�֣�

class Solution {
public:
    int N;//����һ��ȫ�ֱ���
    void dfs(int left,int right,string s,vector<string>& ret)
    {
        
        if(right>left)//��������ű������Ŷ࣬˵����Ч,�򷵻�
            return;
        if(left>N)//�����������������N���������ⲻ��������
            return;
        if(left==right&&right==N)//����������Ŷ��ﵽ��ָ������������Խ�����ӵ������б���
        {
            ret.push_back(s);
            return;
        }
        //�������������û�����㣬���Լ����µ������ź�������
        dfs(left+1,right,s+"(",ret);
        dfs(left,right+1,s+")",ret);
    }
    
    vector<string> generateParenthesis(int n) {
        N=n;
        if(N<0)
            return {};
        vector<string> ret;
        dfs(0,0,"",ret);
        return ret;
    }
};