��Ŀ��
���������ַ������ӵ�һ�ַ�����ɾ���ڶ����ַ��������е��ַ������磬���롱They are students.���͡�aeiou������ɾ��֮��ĵ�һ���ַ�����ɡ�Thy r stdnts.��

����1��

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    for(int i=0;i<s2.size();i++)//�ȱ����̵��ַ���
    {
        for(int j=0;j<s1.size();j++)//��ȥ���ַ������Ҷ�Ӧ���ַ�
        {
            if(s2[i]==s1[j])//�����ˣ���ɾ��
            {
                s1.erase(j,1);
            }
        }
    }
    cout<<s1<<endl;
}

����2��

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1;
    string s2;
    getline(cin,s1);
    getline(cin,s2);
    int countArray[256]={0};
    for(int i=0;i<s2.size();i++)// ʹ��ӳ��˼����ͳ�ƶ��ַ�����ÿ���ַ����ֵĴ���
    {
        countArray[s2[i]]++;
    }
    
    string ret;
    //����str1��str1[i]��Ӧ�����±��ֵ���Ϊ0�����ʾ����ַ���str2��û�г��ֹ����ͽ���+=��ret��
    for(int i=0;i<s1.size();i++)
    {
        if(countArray[s1[i]]==0)
        {
            ret+=s1[i];
        }
    }
    cout<<ret<<endl;
}