��Ŀ��
 ��һ��byte���ֶ�Ӧ�Ķ�����������1�����������������3�Ķ�����Ϊ00000011���������2��1


#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        int count=0,maxcount=0;
        while(n)
        {
            if(n&1)
            {
                count++;
                maxcount=max(count,maxcount);
            }
            else
                count=0;
            n=n>>1;
        }
        cout<<maxcount<<endl;
    }
    
    return 0;
}