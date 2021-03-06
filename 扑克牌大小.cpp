题目：
扑克牌游戏大家应该都比较熟悉了，一副牌由54张组成，含3~A，2各4张，小王1张，大王1张。牌面从小到大用如下字符和字符串表示（其中，小写joker表示小王，大写JOKER表示大王）:) 
3 4 5 6 7 8 9 10 J Q K A 2 joker JOKER 
输入两手牌，两手牌之间用“-”连接，每手牌的每张牌以空格分隔，“-”两边没有空格，如：4 4 4 4-joker JOKER
请比较两手牌大小，输出较大的牌，如果不存在比较关系则输出ERROR

基本规则：
（1）输入每手牌可能是个子，对子，顺子（连续5张），三个，炸弹（四个）和对王中的一种，不存在其他情况，由输入保证两手牌都是合法的，顺子已经从小到大排列；
（2）除了炸弹和对王可以和所有牌比较之外，其他类型的牌只能跟相同类型的存在比较关系（如，对子跟对子比较，三个跟三个比较），不考虑拆牌情况（如：将对子拆分成个子）
（3）大小规则跟大家平时了解的常见规则相同，个子，对子，三个比较牌面大小；顺子比较最小牌大小；炸弹大于前面所有的牌，炸弹之间比较牌面大小；对王是最大的牌；
（4）输入的两手牌不会出现相等的情况。



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
        string card2=str.substr(index+1);//获得从index+1位置之后的
        //获得每手牌的个数
        int cnt1=count(card1.begin(),card1.end(),' ')+1;
        int cnt2=count(card2.begin(),card2.end(),' ')+1;
        //获得每手牌的第一张
        string first1=card1.substr(0,card1.find(' '));
        string first2=card2.substr(0,card2.find(' '));
        string s="345678910JQKA2jokerJOKER";
        if(cnt1==cnt2)
        {
            //只要牌数相等，则第一张牌大的即为大
            if(s.find(first1)>s.find(first2))
                cout<<card1<<endl;
            else
                cout<<card2<<endl;
        }
        else//牌数不等
        {
            //牌数不相同，说明类型不同,只有炸弹可以和其它牌比较
            //其它类型都是错误的
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