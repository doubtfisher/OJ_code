��Ŀ��
��Ŀ��
������������ڣ���������һ��ĵڼ��졣��
��ϸ������
����ĳ��ĳ��ĳ�գ��ж���һ������һ��ĵڼ��죿


���룺
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