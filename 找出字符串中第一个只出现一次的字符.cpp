��Ŀ��
�ҳ��ַ����е�һ��ֻ����һ�ε��ַ���



ʵ�����£�
#include <iostream>
#include <string>

using namespace std;
int main()
{
    string s;
    while(cin>>s)
    {
        int count[256]={0};
        for(size_t i=0;i<s.size();i++)
        {
            count[s[i]]++;
        }
        bool findflag=false;
        for(size_t i=0;i<s.size();i++)
        {
            if(count[s[i]]==1)
            {
                cout<<s[i]<<endl;
                findflag=true;
                break;
            }
        }
        if(findflag==false)
            cout<<-1<<endl;
    }
    return 0;
}