��Ŀ��
���������������ַ������������ǵĺͣ��ö����Ʊ�ʾ����

����Ϊ�ǿ��ַ�����ֻ��������?1?��?0��


ʾ��?1:


����:
 a = "11", b = "1"

���: "100"

ʾ��?2:


����: a = "1010", b = "1011"

���: "10101"

˼·ʵ�֣������ʵ���������ַ�������е���ֻ�ǽ�λ��������һ�����ѡ�

����ʵ�֣�
class Solution {
public:
    string addBinary(string a, string b) {
        int end1=a.size()-1;
        int end2=b.size()-1;
        int val1=0,val2=0;
        string ret;
        int sumret=0;
        int next=0;
        while(end1>=0||end2>=0)
        {
            if(end1>=0)
                val1=a[end1--]-'0';
            else
                val1=0;
            if(end2>=0)
                val2=b[end2--]-'0';
            else
                val2=0;
            
            sumret=val1+val2+next;
            if(sumret>=2)
            {
                next=1;
                sumret-=2;
            }
            else
                next=0;
            
            ret+=(sumret+'0');
        }
        if(next==1)
        {
            ret+='1';
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
};