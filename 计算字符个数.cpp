��Ŀ��
д��һ�����򣬽���һ������ĸ��������ɵ��ַ�������һ���ַ���Ȼ����������ַ����к��и��ַ��ĸ����������ִ�Сд��

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    cin>>str;
    char ch;
    cin>>ch;
    int count=0;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]==ch||str[i]==ch-32)
        {
            count++;
        }
    }
    cout<<count<<endl;
}