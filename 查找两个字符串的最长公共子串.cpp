//��Ŀ��
//���������ַ���a,b�е�������Ӵ������ж��������ڽ϶̴������ȳ��ֵ��Ǹ���
//��������:���������ַ���
//�������:�����ظ����ֵ��ַ�
//ʾ��1
//���룺abcdefghijklmnop
            abcsafjklmnopqrstuvw
//�����jklmnop



#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1,s2;
    while(cin>>s1>>s2)
    {
        if(s1.size()<s2.size())
        {
        swap(s1,s2);
        }
        string ret;
        for(size_t  i=0;i<s2.size();i++)
        {
           for(size_t  j=i;j<s2.size();j++)
           {
               string tmp=s2.substr(i,j-i+1);
               if(int(s1.find(tmp))<0)
               {
                   break;
               }
               else if(ret.size()<tmp.size())
               {
                  ret=tmp;
               }
           }
        }
        cout<<ret<<endl;
     }
      return 0;
}
