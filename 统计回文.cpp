��Ŀ��
���Ĵ�����һ�������ͷ�����һ�����ַ��������硰level�����ߡ�noon���ȵȾ��ǻ��Ĵ��������ǳ�ϲ������ӵ�жԳ����Ļ��Ĵ������յ�ʱ�����õ���������ֱ����ַ���A���ַ���B���������ǳ�������û�а취���ַ���B�����ַ���Aʹ�������ַ�����һ�����Ĵ�������ܻ��������󣬰�����Ѱ���ж����ֲ���취����ʹ�´���һ�����Ĵ�������ַ���B�����λ�ò�ͬ�Ϳ���Ϊ��һ���İ취��
���磺
A = ��aba����B = ��b����������4�ְ�B����A�İ취��
* ��A�ĵ�һ����ĸ֮ǰ: "baba" ���ǻ��� 
* �ڵ�һ����ĸ��a��֮��: "abba" �ǻ��� 
* ����ĸ��b��֮��: "abba" �ǻ��� 
* �ڵڶ�����ĸ'a'֮�� "abab" ���ǻ��� 
�������������Ĵ�Ϊ2��



#include <iostream>
#include <string>
using namespace std;

//�ж��Ƿ��ǻ���
bool IsPalindrome(const string& str)
{
    int begin=0;
    int end=str.size()-1;
    while(begin<end)
    {
        if(str[begin]!=str[end])
            return false;
        
        begin++;
        end--;
    }
    return true;
}

int main()
{
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    int count=0;
    // ���ַ���2���뵽�ַ���1��ÿ��λ�ã����ж��Ƿ��ǻ��ģ�����ǣ�����++
    for(int i=0;i<=s1.size();i++)
    {
        string tmp=s1;
        tmp.insert(i,s2);
        if(IsPalindrome(tmp))
            count++;
    }
    cout<<count<<endl;
}