��Ŀ������
���������ڣ�����������֮�������������������������������ǹ涨����֮�������Ϊ����
��������:
�ж������ݣ�ÿ�����������У��ֱ��ʾ�������ڣ���ʽΪYYYYMMDD
�������:
ÿ���������һ�У������ڲ�ֵ


������
���ȼ����������ھ���0000��0��1�յ�������Ȼ����������֮��Ĳ�ֵ��

����ʵ�֣�

#include <stdio.h>
#include <math.h>
#include  <iostream>

using namespace std;

int mon[13]={0,31,59,90,120,151,181,212,243,273,304,334,365};

bool IsLeapYear(int year)//�ж��Ƿ�Ϊ����
{
    if((year%4==0&&year%100!=0)
      ||year%400==0)
        return true;
    else
        return false;
}

int cal(int y,int m,int d)//���������գ��������0000��0��1�յ�������
{
    int day=y*365+mon[m-1]+d-1;
    if(IsLeapYear(y)&&m>2)
        return day+1;
    else
        return day;
}
int main()
{
    int date[2];
    int year,month,day;
    for(int i=0;i<2;i++)//ѭ��������������
    {
        scanf("%4d%2d%2d",&year,&month,&day);
        date[i]=cal(year,month,day);
    }
    cout<<abs(date[0]-date[1])+1<<endl;
}