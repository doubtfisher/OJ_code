��Ŀ��


NowCoder�����ڳ���Σ�պ���ı�������Ϊ�����棬���״η��������룬���ھ��ӵ���Ϣ���ݡ��������Ǿ����е�һ�����٣���Ҫ�ѷ���������Ϣ�������������
������Ľ�����
��Ϣ���ܵİ취�ǣ�����Ϣԭ���е�ÿ����ĸ���ֱ��ø���ĸ֮��ĵ�5����ĸ�滻�����磺��Ϣԭ���е�ÿ����ĸA ���ֱ��滻����ĸF���������ַ��� �䣬������Ϣԭ�ĵ�������ĸ���Ǵ�д�ġ������е���ĸ��ԭ���е���ĸ��Ӧ��ϵ���¡�

������ĸ��A B C D E F G H I J K L M N O P Q R S T U V W X Y Z

ԭ����ĸ��V W X Y Z A B C D E F G H I J K L M N O P Q R S T U

������
����=ԭ��+5                                        
ԭ��= ���� - 5
������-'A'>5 ��ֱ��ת�� ;
���� :
ԭ��='A'-5+26     ԭ��= ���� + 21

ʵ�ִ������£�

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