��Ŀ��
������n���ַ����ַ��������������ַ������ȶ��ǲ�ͬ�ġ��������ѧϰ���������ַ��������򷽷��� 1.�����ַ������ֵ����������磺
"car" < "carriage" < "cats" < "doggies < "koala"
2.�����ַ����ĳ����������磺
"car" < "cats" < "koala" < "doggies" < "carriage"
������֪���Լ�����Щ�ַ�������˳���Ƿ��������������򷽷�������Ҫæ�ų���Ҷ��������Ҫ������æ��֤��

#include <iostream>
#include <string>
#include <vector>
#include <string.h>
using namespace std;

bool IsLexicSort(vector<string> &v)//�ж��ַ����Ƿ��Ǹ����ֵ�������
{
    for(size_t i=0;i<v.size()-1;i++)
    {
        if(strcmp(v[i].c_str(),v[i+1].c_str())>0)
            return false;
    }
    return true;
}

bool IsLengthSort(vector<string> &v)//�ж��ַ����Ƿ��Ǹ��ݳ�������
{
    for(size_t i=0;i<v.size()-1;i++)
    {
        if(v[i].size()>v[i+1].size())
            return false;
    }
    return true;
}
int main()
{
    int n;
    cin>>n;
    vector<string> v(n);
    for(size_t i=0;i<n;i++)
    {
        cin>>v[i];
    }
    
    bool Length=IsLengthSort(v);
    bool Lexico=IsLexicSort(v);
    if(!Length && Lexico)
    {
        cout<<"lexicographically"<<endl;
    }
    if(Length && !Lexico)
    {
        cout<<"lengths"<<endl;
    }
    if(Length && Lexico)
    {
        cout<<"both"<<endl;
    }
     if(!Length && !Lexico)
    {
        cout<<"none"<<endl;
    }
    return 0;
}