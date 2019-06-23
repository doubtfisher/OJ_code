题目：小易来到了一条石板路前，每块石板上从1挨着编号为：1、2、3.......
这条石板路要根据特殊的规则才能前进：对于小易当前所在的编号为K的 石板，小易单次只能往前跳K的一个约数(不含1和K)步，即跳到K+X(X为K的一个非1和本身的约数)的位置。 小易当前处在编号为N的石板，他想跳到编号恰好为M的石板去，小易想知道最少需要跳跃几次可以到达。


分析：
将1 - M个石板看做一个结果数组stepNum，每个stepNum[i]储存着从起点到这一步最小的步数，其中0为不能到达。
从起点开始对stepNum进行遍历，先求i的所有约数（即从stepNum[i]能走的步数），
然后更新那几个能到达的位置的最小步数.如果不能到达则更新为此时位置的最小步数 + 1，
如果是能到达的就更新为min（已记录的最小步数，此处的最小步数 + 1）），遍历一遍后得到结果。


#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

void NumberFactor(int n,vector<int> &v)
{
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            v.push_back(i);
            if(n/i!=i)
                v.push_back(n/i);
        }
    }
}

int Jump(int n,int m)
{
    vector<int> step(m+1,0);//一开始把数组中的值全都初始化为0
     step[n]=1;//step中下标对应的值记录的是次数
    for(int i=n;i<m;i++)
    {
        vector<int> v;//存的是一个数的所有约束（除掉1和它本身）
        //0代表这个点不能到
        if(step[i]==0)
            continue;
        
        NumberFactor(i,v);
        
        for(int j=0;j<v.size();j++)
        {
            //由位置i出发能到达的点为 step[v[j]+i]
            if((v[j]+i) <= m && step[v[j]+i]!=0)
            {
                step[v[j]+i]=min(step[v[j]+i],step[i]+1);
            }
            else if((v[j]+i)<= m)
            {
                step[v[j]+i]=step[i]+1;
            }
        }
    }
    if(step[m]==0)
        return -1;
    else
        return step[m]-1;//初始化时多给了一步，故需要减1
}

int main()
{
    int n,m;
    cin>>n>>m;
    cout<<Jump(n,m)<<endl;
}


