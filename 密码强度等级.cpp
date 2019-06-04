题目：
密码按如下规则进行计分，并根据不同的得分为密码进行安全等级划分。
       一、密码长度:
       5 分: 小于等于4 个字符
       10 分: 5 到7 字符
       25 分: 大于等于8 个字符
       二、字母:
       0 分: 没有字母
       10 分: 全都是小（大）写字母
       20 分: 大小写混合字母
       三、数字:
       0 分: 没有数字
       10 分: 1 个数字
       20 分: 大于1 个数字
       四、符号:
       0 分: 没有符号
       10 分: 1 个符号
       25 分: 大于1 个符号
       五、奖励:
       2 分: 字母和数字
       3 分: 字母、数字和符号
       5 分: 大小写字母、数字和符号
       最后的评分标准:
       >= 90: 非常安全
       >= 80: 安全（Secure）
       >= 70: 非常强
       >= 60: 强（Strong）
       >= 50: 一般（Average）
       >= 25: 弱（Weak）
       >= 0:  非常弱
对应输出为：
  VERY_WEAK,
   WEAK,    
   AVERAGE,    
   STRONG,     
   VERY_STRONG,
   SECURE,     
   VERY_SECURE 
       请根据输入的密码字符串，进行安全评定。
       注：
       字母：a-z, A-Z
       数字：-9
       符号包含如下： (ASCII码表可以在UltraEdit的菜单view->ASCII Table查看)
       !"#$%&'()*+,-./     (ASCII码：x21~0x2F)
       :;<=>?@             (ASCII<=><=><=><=><=>码：x3A~0x40)
       [\]^_`              (ASCII码：x5B~0x60)
  {|}~                (ASCII码：x7B~0x7E)

代码如下：

#include <iostream>
#include <string>
using namespace std;
int GetLength(const string& str,int len)
{
    if(len<4)
        return 5;
    else if(len<8)
        return 10;
    else
        return 25;
}

int GetChar(const string &str,int len)
{
    int small=0,big=0;
    for(int i=0;i<len;i++)
    {
        if(str[i]>='a'&&str[i]<='z')
            small++;
        if(str[i]>='A'&&str[i]<='Z')
            big++;
    }
    if((small+big)==0)
        return 0;
    if(small>=1&&big>=1)
        return 20;
    if(small==len||big==len)
        return 10;
    return 0;
}

int GetNumber(const string &str,int len)
{
    int num=0;
    for(int i=0;i<len;i++)
    {
        if(str[i]-'0'>=0&&str[i]-'0'<=9)
            num++;
    }
    if(num==0)
        return 0;
    if(num==1)
        return 10;
    if(num>1)
        return 20;
    
    return 0;
}

int GetSymbol(const string &str,int len)
{
    int symbol=0;
    for(int i=0;i<len;i++)
    {
        if(!(str[i]>='a'&&str[i]<='z')
           &&!(str[i]>='A'&&str[i]<='Z')
           &&!(str[i]-'0'>=0&&str[i]-'0'<=9))
        {
            symbol++;
        }
    }
    if(symbol==0)
        return 0;
    if(symbol==1)
        return 10;
    if(symbol>1)
        return 25;
    
    return 0;
}
int GetWard(const string &str,int len)
{
    int sum1=0,sum2=0,sum3=0,sum4=0,sum5=0;
    sum1=GetLength(str,len);
    sum2=GetChar(str,len);
    sum3=GetNumber(str,len);
    sum4=GetSymbol(str,len);
    if(sum2>0&&sum3>0&&sum4==0)
        return 2;
    if(sum2>0&&sum3>0&&sum4>0)
    {
        if(sum2==10)
            return 3;
        else
            return 5;
    }
    
    return 0;
}

int main()
{
    string str;
    while(getline(cin,str))
    {
        int sum1=0,sum2=0,sum3=0,sum4=0,sum5=0;
        int size=str.size();
        sum1=GetLength(str,size);
        sum2=GetChar(str,size);
        sum3=GetNumber(str,size);
        sum4=GetSymbol(str,size);
        sum5=GetWard(str,size);
        if(sum1+sum2+sum3+sum4+sum5>=90)
            cout<<"VERY_SECURE"<<endl;
        else if(sum1+sum2+sum3+sum4+sum5>=80)
            cout<<"SECURE"<<endl;
        else if(sum1+sum2+sum3+sum4+sum5>=70)
            cout<<"VERY_STRONG"<<endl;
        else if(sum1+sum2+sum3+sum4+sum5>=60)
            cout<<"STRONG"<<endl;
        else if(sum1+sum2+sum3+sum4+sum5>=50)
            cout<<"AVERAGE"<<endl;
        else if(sum1+sum2+sum3+sum4+sum5>=25)
            cout<<"WEAK"<<endl;
        else
            cout<<"VERY_WEAK"<<endl;
    }
   
     return 0;
}