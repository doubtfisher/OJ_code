题目：读入一个字符串str，输出字符串str中的连续最长的数字串。

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    getline(cin,str);
    string tmp,ret;
    for(size_t i=0;i<=str.size();i++)
    {
        if(str[i]>='0'&&str[i]<='9')
        {
            tmp+=str[i];
        }
        else
        {
            if(ret.size()< tmp.size())
            {
                ret=tmp;
            }
            else
            {
                tmp.clear();
            }
        }
    }
    cout<<ret<<endl;
}