��Ŀ��
��һ���ַ���ת����һ������(ʵ��Integer.valueOf(string)�Ĺ��ܣ�����string����������Ҫ��ʱ����0)��Ҫ����ʹ���ַ���ת�������Ŀ⺯���� ��ֵΪ0�����ַ�������һ���Ϸ�����ֵ�򷵻�0��

���ⷽ����
class Solution {
public:
    int StrToInt(string str) {
        if(str.empty())
            return 0;
        
        int i=0,flag=1;
        long long ret=0;
        //���˵�ǰ��Ŀո�
        while(str[i]==' ')
        {
            i++;
        }
        //���������ַ�
        if(str[i]=='+')
            i++;
        
        if(str[i]=='-')
        {
            flag=-1;
            i++;
        }
        
        while(str[i]!='\0')
        {
            if(str[i]>='0'&&str[i]<='9')
            {
                int num=str[i]-'0';
                ret=ret*10+flag*num;
            }
            else
            {
                ret=0;
                break;
            }
            i++;
        }
        
        return ret;
    }
};

���ߣ�
class Solution {
public:
    int StrToInt(string str) {
        if(str.size()==0)
            return 0;
        
      int flag=1;
      long long ret=0;
      for(size_t i=0;i<str.size();i++)
      {
          if(isspace(str[i]))
              continue;
          else if(str[i]=='+')
              flag=1;
          else if(str[i]=='-')
              flag=-1;
          else if(str[i]>='0'&&str[i]<='9')
          {
              ret=ret*10+flag*(str[i]-'0');
          }
          else
          {
              ret =0;
              break;
          }     
      }
        return ret;
    }
};
