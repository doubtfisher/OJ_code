��Ŀ��
��һ�仰�ĵ��ʽ��е��ã���㲻���á����� I like beijing. �����������Ϊ��beijing. like I��

#include <iostream>
#include <string.h>
using namespace std;
void reverseStr(char* start,char* end)
{
    while(start!=end)
    {
        char tmp=*end;
       *end=*start;
       *start=tmp;
        end--;
        start++;
    }
}
int main()
{
    char str[1024];
    gets(str);
    char* end=str+strlen(str)-1;
    //1.��ת�����ַ���
    reverseStr(str,end);
    //2.��תÿ������
    char* start=str;
    while(str)
    {
        char* cur=str;
        while(*cur!=' '&&*cur!='\0')
        {
            cur++;
        }
        reverseStr(str,cur-1);
        if(cur!='\0')
            str=cur+1;
        else
            str=cur;
    }
    cout<<start<<endl;
}

����2��

#include <iostream>
#include <string>
using namespace std;

//����cin��ȡ�ַ���ʱ�Զ��ᱻ�ո�ָ�����������һ���ַ����洢�����������
int main()
{
    string s1,s2;
    cin>>s1;
    while(cin>>s2)
    {
        s1=s2+' '+s1;
    }
    cout<<s1<<endl;
}