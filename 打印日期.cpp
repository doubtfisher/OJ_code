��Ŀ������
�������m��һ���еĵ�n�죬�����n���Ǽ��¼��š�
��������:
���������������y(1<=y<=3000)��n(1<=n<=366)��
�������:
�����ж���������ݣ�����ÿ�����ݣ�
�� yyyy-mm-dd�ĸ�ʽ�������ж�Ӧ�����ڴ�ӡ������

������
���ȼ����������ھ���0000��0��1�յ�������Ȼ����������֮��Ĳ�ֵ��

ʵ�ִ������£�

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
       printf("%04d-%02d-%02d\n",year,month,day);//c���Եĸ�ʽ���Ʒ�����ǳ�������ѽ
    }
    return 0;
}