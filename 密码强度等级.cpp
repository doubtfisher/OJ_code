��Ŀ��
���밴���¹�����мƷ֣������ݲ�ͬ�ĵ÷�Ϊ������а�ȫ�ȼ����֡�
       һ�����볤��:
       5 ��: С�ڵ���4 ���ַ�
       10 ��: 5 ��7 �ַ�
       25 ��: ���ڵ���8 ���ַ�
       ������ĸ:
       0 ��: û����ĸ
       10 ��: ȫ����С����д��ĸ
       20 ��: ��Сд�����ĸ
       ��������:
       0 ��: û������
       10 ��: 1 ������
       20 ��: ����1 ������
       �ġ�����:
       0 ��: û�з���
       10 ��: 1 ������
       25 ��: ����1 ������
       �塢����:
       2 ��: ��ĸ������
       3 ��: ��ĸ�����ֺͷ���
       5 ��: ��Сд��ĸ�����ֺͷ���
       �������ֱ�׼:
       >= 90: �ǳ���ȫ
       >= 80: ��ȫ��Secure��
       >= 70: �ǳ�ǿ
       >= 60: ǿ��Strong��
       >= 50: һ�㣨Average��
       >= 25: ����Weak��
       >= 0:  �ǳ���
��Ӧ���Ϊ��
  VERY_WEAK,
   WEAK,    
   AVERAGE,    
   STRONG,     
   VERY_STRONG,
   SECURE,     
   VERY_SECURE 
       ���������������ַ��������а�ȫ������
       ע��
       ��ĸ��a-z, A-Z
       ���֣�-9
       ���Ű������£� (ASCII��������UltraEdit�Ĳ˵�view->ASCII Table�鿴)
       !"#$%&'()*+,-./     (ASCII�룺x21~0x2F)
       :;<=>?@             (ASCII<=><=><=><=><=>�룺x3A~0x40)
       [\]^_`              (ASCII�룺x5B~0x60)
  {|}~                (ASCII�룺x7B~0x7E)

�������£�

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