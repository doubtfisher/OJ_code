��Ŀ��
����һ���ַ����������ҳ����в������ظ��ַ�����Ӵ��ĳ��ȡ�
ʾ��?1:
����: "abcabcbb"
���: 3 
����: ��Ϊ���ظ��ַ�����Ӵ��� "abc"�������䳤��Ϊ 3��

ʾ�� 2:
����: "bbbbb"
���: 1
����: ��Ϊ���ظ��ַ�����Ӵ��� "b"�������䳤��Ϊ 1��

˼·������
��¼ÿ�������ظ�֮ǰ����Ӵ�len������ret�Աȣ�������ret�͸�ֵ��ret

ʵ�ִ��룺class Solution {
    public int lengthOfLongestSubstring(String s) {
        int ret=0;
        for(int i=0;s[i]!='\0';i++)
        {
            unordered_set<char> str;
            int len=0;
            for(int j=i;s[j]!='\0';j++)
            {
                //������������ֵΪk��Ԫ�أ��������ҵ���Ԫ��������Ϊunordered_set�����������ظ�ֵ������ζ����������д��ھ��и�ֵ��Ԫ�أ���ú���ʵ�ʷ���1�����򷵻��㡣
                if(str.count(s[i]))
                    break;
                str.insert(s[i]);
                len++;
            }
            ret=len>ret?len:ret;
        }
        return ret;
    }
}
