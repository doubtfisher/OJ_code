��Ŀ��
�˿�����Ϸ���Ӧ�ö��Ƚ���Ϥ�ˣ�һ������54����ɣ���3~A��2��4�ţ�С��1�ţ�����1�š������С�����������ַ����ַ�����ʾ�����У�Сдjoker��ʾС������дJOKER��ʾ������:) 
3 4 5 6 7 8 9 10 J Q K A 2 joker JOKER 
���������ƣ�������֮���á�-�����ӣ�ÿ���Ƶ�ÿ�����Կո�ָ�����-������û�пո��磺4 4 4 4-joker JOKER
��Ƚ������ƴ�С������ϴ���ƣ���������ڱȽϹ�ϵ�����ERROR

��������
��1������ÿ���ƿ����Ǹ��ӣ����ӣ�˳�ӣ�����5�ţ���������ը�����ĸ����Ͷ����е�һ�֣���������������������뱣֤�����ƶ��ǺϷ��ģ�˳���Ѿ���С�������У�
��2������ը���Ͷ������Ժ������ƱȽ�֮�⣬�������͵���ֻ�ܸ���ͬ���͵Ĵ��ڱȽϹ�ϵ���磬���Ӹ����ӱȽϣ������������Ƚϣ��������ǲ���������磺�����Ӳ�ֳɸ��ӣ�
��3����С��������ƽʱ�˽�ĳ���������ͬ�����ӣ����ӣ������Ƚ������С��˳�ӱȽ���С�ƴ�С��ը������ǰ�����е��ƣ�ը��֮��Ƚ������С�������������ƣ�
��4������������Ʋ��������ȵ������



#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string str;
    getline(cin,str);
    if(str.find("joker JOKER")!=-1)
    {
        cout<<"joker JOKER"<<endl;
    }
    else
    {
        int index=str.find("-");
        string card1=str.substr(0,index);
        string card2=str.substr(index+1);//��ô�index+1λ��֮���
        //���ÿ���Ƶĸ���
        int cnt1=count(card1.begin(),card1.end(),' ')+1;
        int cnt2=count(card2.begin(),card2.end(),' ')+1;
        //���ÿ���Ƶĵ�һ��
        string first1=card1.substr(0,card1.find(' '));
        string first2=card2.substr(0,card2.find(' '));
        string s="345678910JQKA2jokerJOKER";
        if(cnt1==cnt2)
        {
            //ֻҪ������ȣ����һ���ƴ�ļ�Ϊ��
            if(s.find(first1)>s.find(first2))
                cout<<card1<<endl;
            else
                cout<<card2<<endl;
        }
        else//��������
        {
            //��������ͬ��˵�����Ͳ�ͬ,ֻ��ը�����Ժ������ƱȽ�
            //�������Ͷ��Ǵ����
            if(cnt1==4)
            {
                cout<<card1<<endl;
            }
            else if(cnt2==4)
            {
                cout<<card2<<endl;
            }
            else
            {
                cout<<"ERROR"<<endl;
            }
        }
    }
    return 0;
}