��Ŀ��
һ�������� N ��Ԫ�أ�����������������͡� ���磺[-1,2,1]������������������Ϊ[2,1]�����Ϊ 3��


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