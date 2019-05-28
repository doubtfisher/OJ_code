题目：
将一个字符串转换成一个整数(实现Integer.valueOf(string)的功能，但是string不符合数字要求时返回0)，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0。

解题方法：
class Solution {
public:
    int StrToInt(string str) {
        if(str.empty())
            return 0;
        
        int i=0,flag=1;
        long long ret=0;
        //过滤掉前面的空格
        while(str[i]==' ')
        {
            i++;
        }
        //处理特殊字符
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

或者：
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
