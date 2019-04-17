
//题目：


//今年公司年会的奖品特别给力，但获奖的规矩却很奇葩：
1. 首先，所有人员都将一张写有自己名字的字条//放入抽奖箱中；
2. 待所有字条加入完毕，每人从箱中取一个字条；
3. 如果抽到的字条上写的就是自己的名//字，那么“恭喜你，中奖了！”
现在告诉你参加晚会的人数，请你计算有多少概率会出现无人获奖？


//分析：因为是不放回抽取，总的有n！的可能。假定5个人来进行抽奖，有多少种抽法？因为是不放回抽，//所以第一个人有5种抽法，
   第二个人有4种抽法，依次类推
   总共就是5！ 对有5的阶乘种抽法。这是分母
//，分子就是存在多少种情况每个人拿不到自己的名字，这里要使用错排算法：D(n) = (n-1) [D(n-2) + D//(n-1)]


#include <iostream>
using namespace std;
double GetStaggered(int n)//获得错排算法的次数
{
    if(n==1)
        return 0;
    if(n==2)
        return 1;
        
    return (n-1)*(GetStaggered(n-1)+GetStaggered(n-2));
}
double GetFactor(int n)//计算n的阶乘
{
  if(n<3)
  {
   return n;
  }
  return n*GetFactor(n-1);
}
int main()
{
   int n;
    while(cin>>n)
    {
        printf("%.2f%%\n",100.0*(GetStaggered(n)/GetFactor(n)));
    }
    return 0;
}