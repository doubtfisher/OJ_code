��Ŀ��
����һ������������������������1�ĸ�����

����1��n&n-1��Ϊ0

#include <iostream>
using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        int count=0;
        while(n)
        {
            n=n&(n-1);
            count++;
        }
        cout<<count<<endl;
    }
    return 0;
}

����2��

#include <iostream>
using namespace std;

int main()
{
    int n=0;
    while(cin>>n)
    {
        int count=0;
        while(n)
        {
            if(n&1)
                count++;
            n>>=1;
        }
        cout<<count<<endl;
    }
    return 0;
}

����3��
#include <iostream>
using namespace std;

int main()
{
    int n=0;
    while(cin>>n)
    {
      int count=0;
      while(n)
      {
          if(n%2==1)
              count++;
          n/=2;
      }
      cout<<count<<endl;
    }
    return 0;
}