题目：
小喵们很喜欢把自己装进容器里的(例如碗)，但是要是碗的周长比喵的身长还短，它们就进不去了。
现在告诉你它们的身长，和碗的半径，请判断一下能否到碗里去。


实现代码如下：

#include <iostream>
using namespace std;

int main()
{
    double n, r;
    while(cin>>n>>r)
    {
        double length=3.14*r*2;
        if(length<n)
        {
            cout<<"No"<<endl;
        }
        else
        {
            cout<<"Yes"<<endl;
        }
    }
    return 0;
}