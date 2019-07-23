题目描述：
给出年分m和一年中的第n天，算出第n天是几月几号。
输入描述:
输入包括两个整数y(1<=y<=3000)，n(1<=n<=366)。
输出描述:
可能有多组测试数据，对于每组数据，
按 yyyy-mm-dd的格式将输入中对应的日期打印出来。

分析：
首先计算两个日期距离0000年0月1日的天数，然后再求他们之间的差值。

实现代码如下：

#include<iostream>
using namespace std;
 
int GetMonthDay(int year ,int month)
{
    int array[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(month==2&&(year%4==0&&year%100!=0
       ||year%400==0))
    {
        return 29;
    }
    return array[month];
}
 
int main()
{
    int year;
    int day;
    int month=0;
   while(cin>>year>>day)
   {
       while(day>GetMonthDay(year,month))
        {
            if(month==12)
            {
                year++;
                month=1;
            }
            day-=GetMonthDay(year,month);
            month++;
        }
       printf("%04d-%02d-%02d\n",year,month,day);//c语言的格式控制符真的是超级好用呀
    }
    return 0;
}