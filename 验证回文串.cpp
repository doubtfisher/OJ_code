���⣺
����һ���ַ�������֤���Ƿ��ǻ��Ĵ���ֻ������ĸ�������ַ������Ժ�����ĸ�Ĵ�Сд�����ǽ����ַ�������Ϊ��Ч�Ļ��Ĵ���



�����������Ŀ������֮ǰѧ�Ŀ��������ǰ��ָ��˼���е��񣬸�������ָ�룬һ����ǰ����ߣ�ȥ�������ַ�����ĸ��һ��ָ��Ӻ���ǰ�ߣ�ȥ�������ַ�����ĸ���ҵ����ж������Ƿ���ȣ������ȣ�������жϣ�ֱ���ַ���������ָ������ʱ������ȣ���Ϊ���Ĵ��������ǻ��Ĵ���

ʵ�ִ��룺
class Solution {
public:
    bool isLetteOrNumber(char ch)
    {
        return (ch>='0'&&ch<='9')
            ||(ch>='a'&&ch<='z')
            ||(ch>='A'&&ch<='Z');
    }
    
    bool isPalindrome(string s) {
        int begin=0;
        int end=s.size()-1;
        while(begin<end)
        {
            while(begin<end&&!isLetteOrNumber(s[begin]))//��ǰ������ȥ��һ�������ַ�������ĸ
            {
                begin++;
            }
             while(begin<end&&!isLetteOrNumber(s[end]))//�Ӻ���ǰ��ȥ��һ�������ַ�������ĸ
            {
                end--;
            }
            if((s[begin]+32-'a')%32!=(s[end]+32-'a')%32)//����32��Ŀ���Ƿ�ֹ��д��ĸ�����ɸ�������ȥa��Ŀ�����ų����ֵ����У�
            {
                return false;
            }
            else
            {  
                begin++;
                end--;
            }
        }
        return true;  
    }
};

��Ҫ˵��˵���ǣ��������ϸ�����кܶ���Ҫע��ĵط������Ҵ�Сд�ĵط�������⣬��ʱ�����ṩ������һ�ְ취�����������⣬����������£�

class Solution {
public:
    bool isLetteOrNumber(char ch)
    {
        return (ch>='0'&&ch<='9')
            ||(ch>='a'&&ch<='z')
            ||(ch>='A'&&ch<='Z');
    }
    
    bool isPalindrome(string s) {
        for(auto& ch:s)
        {
            if(ch>='a'&&ch<='z')
            {
                ch-=32;//�����Сд����ͳһת��Ϊ��д
            }
        }
        int begin=0;
        int end=s.size()-1;
        while(begin<end)
        {
            while(begin<end&&!isLetteOrNumber(s[begin]))//��ǰ������ȥ��һ�������ַ�������ĸ
            {
                begin++;
            }
             while(begin<end&&!isLetteOrNumber(s[end]))//�Ӻ���ǰ��ȥ��һ�������ַ�������ĸ
            {
                end--;
            }
            if(s[begin]!=s[end])
            {
                return false;
            }
            else
            {  
                begin++;
                end--;
            }
        }
        return true;  
    }
};