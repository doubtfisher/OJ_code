��Ŀ��
�����������ڼ�����У�ͨ���һ�������﷨���㷺Ӧ�����ļ����������ݿ⡢������ʽ��������Ҫ���λʵ���ַ���ͨ������㷨��
Ҫ��
ʵ������2��ͨ�����
*��ƥ��0�������ϵ��ַ����ַ���Ӣ����ĸ������0-9��ɣ������ִ�Сд����ͬ��
����ƥ��1���ַ�

���룺
ͨ������ʽ��
һ���ַ�����

�����
����ƥ��Ľ������ȷ���true���������false



#include <iostream>
#include <string>
using namespace std;

bool Match(const char* pattern,const char* str)
{
    if(*pattern=='\0'&&*str=='\0')
        return true;
    if(*pattern=='\0'||*str=='\0')
        return false;
    
    if(*pattern=='?')
        return Match(pattern+1,str+1);
    else if(*pattern=='*')
        return Match(pattern+1,str)//����*�ţ�ƥ��0��(str��Ų��)
        ||Match(pattern+1,str+1)//ƥ��1�������߶���ǰŲ��һ���ַ���
        ||Match(pattern,str+1);//��ƥ����(str��ǰŲ��һ���ַ�)
    else if(*pattern==*str)
        return Match(pattern+1,str+1);//�����ǰ�ַ���ȣ�ƥ����һ���ַ�
    
    return false;
}

int main()
{
    string pattern;
    string str;
    while(cin>>pattern>>str)
    {
         bool ret=Match(pattern.c_str(),str.c_str());
        if(ret)
            cout<<"true"<<endl;
        else
            cout<<"false"<<endl;
    }
    return 0;
}