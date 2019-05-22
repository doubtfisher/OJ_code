题目：
对字符串中的所有单词进行倒排。
说明：
1、每个单词是以26个大写或小写英文字母构成；
2、非构成单词的字符均视为单词间隔符；
3、要求倒排后的单词间隔符以一个空格表示；如果原字符串中相邻单词间有多个间隔符时，倒排转换后也只允许出现一个空格间隔符；
4、每个单词最长20个字母；

//测试用例只能过%90........

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string str;
    while(getline(cin,str))
    {
        string s;
        for(int i=0;i<str.size();i++)
        {
            if((str[i]==' ')||(str[i]>='A'&&str[i]<='Z')||
               (str[i]>='a'&&str[i]<='z'))
            {
                s+=str[i];
            }
        }
        reverse(s.begin(),s.end());
        auto start=s.begin();
        while(start!=s.end())
        {
            auto end=start;
            while(end!=s.end()&&*end!=' ')
            {
                end++;
            }
            reverse(start,end);
            if(end!=s.end())
            {
                start=end+1;
            }
            else
            {
                start=end;
            }
        }
        cout<<s<<endl;
        } 
}

//测试用例完全通过的第二种方法

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string str;
    while(getline(cin,str))
    {
        //从前往后遍历字符串，遇到是单词就放入vector，最后反向输出vector。
        vector<string> vs;
        vs.clear();
         string s;
        for(int i=0;i<str.size();i++)
        {
            if((str[i]>='A'&&str[i]<='Z')||
              (str[i]>='a'&&str[i]<='z'))
            {
                s+=str[i];
            }
            else
            {
                if(s.size()>0)
                {
                    vs.push_back(s);
                    s.clear();
                }
            }
        }
        if(s.size()>0)
         {
             vs.push_back(s);
         }
        for(int i=vs.size()-1;i>0;i--)
        {
            cout<<vs[i]<<' ';
        }
        cout<<vs[0]<<endl;
        return 0;
    }   
}