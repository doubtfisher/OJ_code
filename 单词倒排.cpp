��Ŀ��
���ַ����е����е��ʽ��е��š�
˵����
1��ÿ����������26����д��СдӢ����ĸ���ɣ�
2���ǹ��ɵ��ʵ��ַ�����Ϊ���ʼ������
3��Ҫ���ź�ĵ��ʼ������һ���ո��ʾ�����ԭ�ַ��������ڵ��ʼ��ж�������ʱ������ת����Ҳֻ�������һ���ո�������
4��ÿ�������20����ĸ��

//��������ֻ�ܹ�%90........

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string str;
    while(getline(cin,str))
    {
        string s;
        for(int i=0;i<str.size();i++)
        {
            if((str[i]==' ')||(str[i]>='A'&&str[i]<='Z')||
               (str[i]>='a'&&str[i]<='z'))
            {
                s+=str[i];
            }
        }
        reverse(s.begin(),s.end());
        auto start=s.begin();
        while(start!=s.end())
        {
            auto end=start;
            while(end!=s.end()&&*end!=' ')
            {
                end++;
            }
            reverse(start,end);
            if(end!=s.end())
            {
                start=end+1;
            }
            else
            {
                start=end;
            }
        }
        cout<<s<<endl;
        } 
}

//����������ȫͨ���ĵڶ��ַ���

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string str;
    while(getline(cin,str))
    {
        //��ǰ��������ַ����������ǵ��ʾͷ���vector����������vector��
        vector<string> vs;
        vs.clear();
         string s;
        for(int i=0;i<str.size();i++)
        {
            if((str[i]>='A'&&str[i]<='Z')||
              (str[i]>='a'&&str[i]<='z'))
            {
                s+=str[i];
            }
            else
            {
                if(s.size()>0)
                {
                    vs.push_back(s);
                    s.clear();
                }
            }
        }
        if(s.size()>0)
         {
             vs.push_back(s);
         }
        for(int i=vs.size()-1;i>0;i--)
        {
            cout<<vs[i]<<' ';
        }
        cout<<vs[0]<<endl;
        return 0;
    }   
}