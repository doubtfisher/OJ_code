题目：
            1

         1  1  1

      1  2  3  2  1

   1  3  6  7  6  3  1

1  4  10 16 19  16 10  4  1

//以上三角形的数阵，第一行只有一个数1，以下每行的每个数，是恰好是它上面的数，左上角数到右上角//的数，3个数之和（如果不存在某个数，认为该数就是0）。

//求第n行第一个偶数出现的位置。如果没有偶数，则输出-1。例如输入3,则输出2，输入4则输出3。
//输入n(n <= 1000000000)



#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        vector<vector<int>> v(n,vector<int>(2*n-1,0));
         v[0][0]=1;
        for(size_t i=1;i<n;i++)
        {
            //每一行的第一列和最后一列都初始化为1
            v[i][0]=v[i][2*i]=1;
            for(size_t j=1;j<=2*i;j++)
            {
                //每一行的第二列是上一行的那一列和前一列的和，是两个元素之和
                if(j==1)
                {
                    v[i][j]=v[i-1][j]+v[i-1][j-1];
                }
                else//其余情况是三个元素之和
                {
                    v[i][j]=v[i-1][j]+v[i-1][j-1]+v[i-1][j-2];
                }
            }
        }
        int ret=0;
        for(ret=0;ret<2*n-1;ret++)
        {
            if(v[n-1][ret]!=0&&v[n-1][ret]%2==0)
            {
                cout<<ret+1<<endl;
                break;
            }
        }
       if(ret==2*n-1)
       {
           cout<<-1<<endl;
       }
     }
    
}