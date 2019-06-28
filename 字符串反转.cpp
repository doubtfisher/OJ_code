题目：
写出一个程序，接受一个字符串，然后输出该字符串反转后的字符串。

#include <iostream>
#include <string>
using namespace std;

string Reverse(string& s)
{
    if(s.empty())
        return s;
    int start=0;
    int end=s.size()-1;
    while(start<end)
    {
        swap(s[start],s[end]);
        start++;
        end--;
    }
    return s;
}

int main()
{
  string s;
  getline(cin,s);
  cout<<Reverse(s)<<endl;
  return 0;
}