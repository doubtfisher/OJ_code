//题目：淘宝网店
//NowCoder在淘宝上开了一家网店。他发现在月份为素数的时候，当月每天能赚1元；否则每天能赚2元。
//现在给你一段时间区间，请你帮他计算总收益有多少。

#include <iostream>
using namespace std;

int IsLeapYear(int y)//判断是否是闰年
{
    if((y%4==0&&y%100!=0)||y%400==0)
        return 1;
    return 0;
}

bool IsPrime(int n)//判断是否是质数月
{
    return n==2||n==3||n==5||n==7||n==11;
}

int HowManyDay(int y,int m,int d)//判断某一天是这一年的第几天
{
    if(!IsPrime(m))
       d*=2;
    while(--m)
    {
        switch(m)
        {
            case 1:
            case 8:
            case 10:
            case 12:
                d+=31*2;
                break;
            case 3:
            case 5:
            case 7:
                d+=31;
                break;
            case 4:
            case 6:
            case 9:
                d+=30*2;
                break;
            case 11:
                d+=30;
                break;
            case 2:
                d+=28+IsLeapYear(y);
                break;
            default:
                break;
        }
    }
    return d;
}

int Profityear(int y)//足年的天数
{
    int sum=2*31+28+31+2*30+31+2*30+31+2*31+2*30+2*31+30+2*31;
    if(IsLeapYear(y))
        sum+=1;
    return sum;
}

int main()
{
    int year1,month1,day1,year2,month2,day2;
    while(cin>>year1>>month1>>day1>>year2>>month2>>day2)
    {
        int profit=0;
        //这里的day1 - 1虽然有可能会出现0日，但是实际2月0日就相当于1月31日，所以不影响结果
        profit+=Profityear(year1)-HowManyDay(year1,month1,day1-1);
        profit+=HowManyDay(year2,month2,day2);
        if(year1==year2)//如果是同一年,要减掉这一年的天数
            profit-=Profityear(year1);
        //计算中间足年每一年的天数
        for(int i=year1+1;i<year2;i++)
        {
            profit+=Profityear(i);
        }
        cout<<profit<<endl;
    }
    return 0;
}
