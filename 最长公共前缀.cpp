��Ŀ��
��дһ�������������ַ��������е������ǰ׺����������ڹ���ǰ׺�����ؿ��ַ��� ""��

ʾ��?1:


����: ["flower","flow","flight"]

���: "fl"

ʾ��?2:


����: ["dog","racecar","car"]

���: ""

����: ���벻���ڹ���ǰ׺��



˼·������
�ҵ�����ַ����������ĳ���Ϊ��׼���������ַ����ĵ�һ���ַ���ʼ�Աȣ�����һ����ans���ϸ��ַ�������һ��������

����ʵ�֣�
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        if(strs.empty())
            return ans;
        
         //1.�ҵ���С���ַ���
        int n=strs.size();
        string min=strs[0];
        for(int  i=0;i<n;i++)
        {
            if(strs[i].size()<min.size())
            {
                min=strs[i];
            }
        }
        //2.����С���Ǹ��ַ������ű���,�ӵ�һ���ַ���ʼ�Աȣ�����һ����ans���ϸ��ַ�
        int m=min.size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(min[i]!=strs[j][i])
                    return ans;               
            }
            ans+=min[i];
        }
        return ans;
    }
};