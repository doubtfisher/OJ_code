题目：
题目：
根据输入的日期，计算是这一年的第几天。。
详细描述：
输入某年某月某日，判断这一天是这一年的第几天？


代码：
#include <iostream>
using namespace std;
int main()
{
    int days[13]={0,31,59,90,120,151,181,212,243,273,304,334,365};
    int year,month,day;
    while(cin>>year>>month>>day)
    {
        int n=days[month-1];
        n+=day;
        if(month>2&&
          ((year%4==0&&year%100!=0)||year%400==0))
        {
           n+=1;
        }
        cout<<n<<endl;
    }
    return 0;  
}