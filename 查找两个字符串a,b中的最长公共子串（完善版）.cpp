��Ŀ��
���������ַ���a,b�е�������Ӵ������ж��������ڽ϶̴������ȳ��ֵ��Ǹ���

����1��
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str1,str2;
    while(cin>>str1>>str2)
    {
        if(str1.size()>str2.size())//ȷ��str2Ϊ�����ַ���
        {
            swap(str1,str2);
        }
        string ret;
        for(size_t i=0;i<str1.size();i++)//��������
        {
            for(size_t j=i;j<str1.size();j++)//�������Ӵ�
            {
                string tmp=str1.substr(i,j-i+1);
                if((int)(str2.find(tmp))<0)//����һ��Ҫǿת����Ϊfind���ʧ�ܵĻ������ص���npos
                    break;
                else if(tmp.size()>ret.size())//���ϸ��½��
                    ret=tmp;
            }
        }
        cout<<ret<<endl;
    }
    return 0;
}


����2��
ʹ�ö�̬�滮����һ��start��Ǽ���,ע�⽫�϶��Ӵ����ȳ��ֵ��Ǹ������

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    string s1,s2;
   while(cin>>s1>>s2)
   {
        if(s1.size()>s2.size())
            swap(s1,s2);//����s1��̵��ַ���
        int len1=s1.size();
        int len2=s2.size();
        int maxlen=0;
        int start=0;//��ʶ������Ӵ�����ʼλ��
        vector<vector<int> > dp(len1+1,vector<int>(len2+1,0));
        int i,j;
        for(i=1;i<=len1;i++)
        {
            for(j=1;j<=len2;j++)
            {
                if(s1[i-1]==s2[j-1])
                    dp[i][j]= dp[i-1][j-1]+1;
                //����и����Ĺ����Ӵ�������³���
                if(dp[i][j]>maxlen)
                {
                    maxlen=dp[i][j];
                    start=i-maxlen;//��i��β����󳤶�Ϊmax�����Ӵ�����ʼλ��Ϊi-manlen
                }
            }
        }
        cout<<s1.substr(start,maxlen)<<endl;
   }
    return 0;
}