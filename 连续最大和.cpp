题目：
一个数组有 N 个元素，求连续子数组的最大和。 例如：[-1,2,1]，和最大的连续子数组为[2,1]，其和为 3。


#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
         cin>>v[i];
    }
    int sum=v[0];
    int maxsum=v[0];
    for(int i=1;i<n;i++)
    {
         if(sum>0)
         {
              sum+=v[i];
         }
         else
         {
               sum=v[i];
         }
         if( sum > maxsum)
         {
               maxsum=sum;
         }
    }
   cout<<maxsum<<endl;
}