题目：
 求一个byte数字对应的二进制数字中1的最大连续数，例如3的二进制为00000011，最大连续2个1


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