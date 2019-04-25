//题目：

NowCoder每天要给很多人发邮件。有一天他发现发错了邮件，把发给A的邮件发给了B，把发给B//的邮件发给了A。于是他就思考，要给n个人发邮件，在每个人仅收到1封邮件的情况下，有多少种情况是//所有人都收到了错误的邮件？
即没有人收到属于自己的邮件。

//思路：使用的是错排算法:D(n)=(n-1)*(D(n-1)+D(n-2))

#include <iostream>
using namespace std;

int main ()
{
  long long arr[21]={0,0,1};
  for(int i=3;i<21;i++)
  {
      arr[i]=(i-1)*(arr[i-1]+arr[i-2]);
  }
    int n=2;
    while(cin>>n)
    {
        cout<<arr[n]<<endl;
    }
}