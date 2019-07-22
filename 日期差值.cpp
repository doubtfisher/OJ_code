题目描述：
有两个日期，求两个日期之间的天数，如果两个日期是连续的我们规定他们之间的天数为两天
输入描述:
有多组数据，每组数据有两行，分别表示两个日期，形式为YYYYMMDD
输出描述:
每组数据输出一行，即日期差值


分析：
首先计算两个日期距离0000年0月1日的天数，然后再求他们之间的差值。

代码实现：

#include <stdio.h>
#include <math.h>
#include  <iostream>

using namespace std;

int mon[13]={0,31,59,90,120,151,181,212,243,273,304,334,365};

bool IsLeapYear(int year)//判断是否为闰年
{
    if((year%4==0&&year%100!=0)
      ||year%400==0)
        return true;
    else
        return false;
}

int cal(int y,int m,int d)//给出年月日，计算距离0000年0月1日的天数和
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
    for(int i=0;i<2;i++)//循环读入两个日期
    {
        scanf("%4d%2d%2d",&year,&month,&day);
        date[i]=cal(year,month,day);
    }
    cout<<abs(date[0]-date[1])+1<<endl;
}