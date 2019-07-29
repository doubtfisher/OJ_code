//��Ŀ���Ա�����
//NowCoder���Ա��Ͽ���һ�����ꡣ���������·�Ϊ������ʱ�򣬵���ÿ����׬1Ԫ������ÿ����׬2Ԫ��
//���ڸ���һ��ʱ�����䣬������������������ж��١�

#include <iostream>
using namespace std;

int IsLeapYear(int y)//�ж��Ƿ�������
{
    if((y%4==0&&y%100!=0)||y%400==0)
        return 1;
    return 0;
}

bool IsPrime(int n)//�ж��Ƿ���������
{
    return n==2||n==3||n==5||n==7||n==11;
}

int HowManyDay(int y,int m,int d)//�ж�ĳһ������һ��ĵڼ���
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

int Profityear(int y)//���������
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
        //�����day1 - 1��Ȼ�п��ܻ����0�գ�����ʵ��2��0�վ��൱��1��31�գ����Բ�Ӱ����
        profit+=Profityear(year1)-HowManyDay(year1,month1,day1-1);
        profit+=HowManyDay(year2,month2,day2);
        if(year1==year2)//�����ͬһ��,Ҫ������һ�������
            profit-=Profityear(year1);
        //�����м�����ÿһ�������
        for(int i=year1+1;i<year2;i++)
        {
            profit+=Profityear(i);
        }
        cout<<profit<<endl;
    }
    return 0;
}
