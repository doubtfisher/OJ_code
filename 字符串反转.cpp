��Ŀ��
д��һ�����򣬽���һ���ַ�����Ȼ��������ַ�����ת����ַ�����

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