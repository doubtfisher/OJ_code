题目：
   1
 1  1  1
1  2  3  2  1
1  3  6  7  6  3  1
1  4  10 16 19  16 10  4  1
以上三角形的数阵，第一行只有一个数1，以下每行的每个数，是恰好是它上面的数，左上角数到右上角的数，3个数之和（如果不存在某个数，认为该数就是0）。
求第n行第一个偶数出现的位置。如果没有偶数，则输出-1。例如输入3,则输出2，输入4则输出3。



#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        int m=2*n-1;
        vector<vector<int>> v(n,vector<int>(m,0));
        v[0][0]=1;
        for(int i=1;i<n;i++)
        {
            //第一列和最后一列都为1
            v[i][0]=v[i][2*i]=1;
            for(int j=1;j<2*i;j++)
            {
               //每一行的第二列是它前一行的两个数之和
                if(j==1)
                    v[i][j]=v[i-1][j-1]+v[i-1][j];
                else
                   v[i][j]=v[i-1][j-2]+v[i-1][j-1]+v[i-1][j];
            }
        }
        int k=0;
        for(k=0;k<m;k++)
        {
            if(v[n-1][k]%2==0&&v[n-1][k]!=0)
            {
                cout<<k+1<<endl;
                break;
            }
        }
        if(k==m)
        {
            cout<<-1<<endl;
        }
    }
    return 0;
}