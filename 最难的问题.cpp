题目：


NowCoder生活在充满危险和阴谋的年代。为了生存，他首次发明了密码，用于军队的消息传递。假设你是军团中的一名军官，需要把发送来的消息破译出来、并提
供给你的将军。
消息加密的办法是：对消息原文中的每个字母，分别用该字母之后的第5个字母替换（例如：消息原文中的每个字母A 都分别替换成字母F），其他字符不 变，并且消息原文的所有字母都是大写的。密码中的字母与原文中的字母对应关系如下。

密码字母：A B C D E F G H I J K L M N O P Q R S T U V W X Y Z

原文字母：V W X Y Z A B C D E F G H I J K L M N O P Q R S T U

分析：
密码=原文+5                                        
原文= 密码 - 5
当密码-'A'>5 则直接转换 ;
否则 :
原文='A'-5+26     原文= 密码 + 21

实现代码如下：

#include <iostream>
#include <string>
using namespace std;

char Translate(char ch)
{
    int c;
    if(ch>='A'&& ch<='Z')
    {
        c=ch-5;
        if(c<'A')
            c=c+26;
    }
    return c;
}
int main()
{
    string str;
    while(getline(cin,str))
    {
        string res;
        for(int i=0;i<str.size();i++)
        {
            if(str[i]==' ')
                res.push_back(str[i]);
           else
                res.push_back(Translate(str[i]));
        }
        cout<<res<<endl;
    }
    return 0;
}