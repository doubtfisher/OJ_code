��Ŀ��
  ��������Сд��ĸ��ɵ��ַ������� A�������б��е�ÿ���ַ����ж���ʾ��ȫ���ַ��������ظ��ַ�����ɵ��б����磬���һ���ַ���ÿ���ַ����г��� 3 �Σ������� 4 �Σ�����Ҫ�����մ��а������ַ� 3 �Ρ�

����԰�����˳�򷵻ش𰸡�

?


ʾ�� 1��


���룺["bella","label","roller"]

�����["e","l","l"]

ʾ�� 2��


���룺["cool","lock","cook"]

�����["c","o"]
?


��ʾ��


1 <= A.length <= 100

1 <= A[i].length <= 100

A[i][j] ��Сд��ĸ



˼·������
�������ַ����������ڵ���2�� ����ı���Ϊ��һ���ַ���������ÿ���ַ����Ĺ����ַ����ظ���μ��������������ƶ�̬�滮��˼�룬����Ĺ����ַ���Ȼ��ĳ�����ַ����Ĺ����ַ��� ��ô����Ĺ����ַ���Ȼ��ǰ�����ַ����Ĺ����ַ���

ʵ�ִ������£�

class Solution {
public:        
    vector<string> str_to_vec(string s)
    {
        vector<string> vs;
        for(auto ch:s)
        {
            string tmp(1,ch);
            vs.push_back(tmp);
        }
        return vs;
    }
    
    string same_substr(const string& s1,const string& s2)
    {
        int num[26]={0};//���ǵ��ظ����ֵ��ַ�����Ҫһ����������¼ĳ���ַ����һ�α��ҵ���λ��
        string str;
        for(auto ch:s1)//����s1
        {
            int index = s2.find(ch,num[ch-'a']);
            if(index<s2.size()&&index>=0)
            {
                str+=ch;
               num[ch-'a']=index+1;
            }
        }
        return str;
    }
    
    vector<string> commonChars(vector<string>& A) {
       vector<string> res;//��Ž����vector
        if(A.size()==1)
            res.push_back(A[0]);
        string tmp=same_substr(A[0],A[1]);
        for(int i=2;i<A.size();i++)
        {
            tmp=same_substr(tmp,A[i]);//��������ͬ���Ӵ�
        }
        res=str_to_vec(tmp);//�������ҵ��Ĺ����Ӵ�ת��Ϊvector<string>����ʽ
        return res;
    }
};