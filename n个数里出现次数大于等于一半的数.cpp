��Ŀ������n��������������ִ������ڵ������鳤��һ�������

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    int n;
    while(cin>>n)
    {
        v.push_back(n);
    }
    int data=v[0];
    int time=1;
    for(int i=1;i<v.size();i++)
    {
       if(time==0)
       {
           data=v[i];
           time=1;
       }
        
       if(data==v[i])
       {
            time++;
       }
       else
       {
            time--;
       }
    }
   cout<<data<<endl;
}