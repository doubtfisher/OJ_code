题目：
二货小易有一个W*H的网格盒子，网格的行编号为0~H-1，网格的列编号为0~W-1。每个格子至多可以放一块蛋糕，任意两块蛋糕的欧几里得距离不能等于2。
对于两个格子坐标(x1,y1),(x2,y2)的欧几里得距离为:( (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2) ) 的算术平方根小易想知道最多可以放多少块蛋糕在网格盒子里。

解题思路：
使用vector<vector<int>>定义一个二维数组，一开始把数组初始化为全能放蛋糕，再根据题意把a[i][j+2]和a[i+1][j]位置不放蛋糕，遍历一遍二维数组，标记处不能放蛋糕的位置，从而也就统计出了当蛋糕的位置数。


#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int row,col;
    int cake=0;
    cin>>row>>col;
    vector<vector<int>> vv;
    vv.resize(row);
    //初始化二维数组为1
    for(size_t i=0;i<row;i++)
    {
        vv[i].resize(col,1);
    }
    //遍历数组，找出不能放蛋糕的位置，并标记为0
    for(size_t i=0;i<row;i++)
    {
        for(size_t j=0;j<col;j++)
        {
            if(vv[i][j]==1)
            {
                 cake++;
                //标记不能放蛋糕的行
                if(i+2<row)
                    vv[i+2][j]=0;
                //标记不能放蛋糕的列
                if(j+2<col)
                    vv[i][j+2]=0;
            }
        }
    }
    cout<<cake<<endl;
}

