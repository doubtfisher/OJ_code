问题：
给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写，我们将空字符串定义为有效的回文串。



分析：这道题目和我们之前学的快速排序的前后指针思想有点像，给定两个指针，一个从前向后走，去找数字字符或字母，一个指针从后向前走，去找数字字符或字母，找到后，判断他们是否相等，如果相等，则继续判断，直到字符串中两个指针相遇时，都相等，则为回文串，否则不是回文串。

实现代码：
class Solution {
public:
    bool isLetteOrNumber(char ch)
    {
        return (ch>='0'&&ch<='9')
            ||(ch>='a'&&ch<='z')
            ||(ch>='A'&&ch<='Z');
    }
    
    bool isPalindrome(string s) {
        int begin=0;
        int end=s.size()-1;
        while(begin<end)
        {
            while(begin<end&&!isLetteOrNumber(s[begin]))//从前往后走去找一个数字字符或者字母
            {
                begin++;
            }
             while(begin<end&&!isLetteOrNumber(s[end]))//从后往前走去找一个数字字符或者字母
            {
                end--;
            }
            if((s[begin]+32-'a')%32!=(s[end]+32-'a')%32)//加上32的目的是防止大写字母被减成负数；减去a的目的是排除数字的误判；
            {
                return false;
            }
            else
            {  
                begin++;
                end--;
            }
        }
        return true;  
    }
};

需要说明说的是；这道题在细节上有很多需要注意的地方，而且大小写的地方不好理解，这时候，又提供了另外一种办法来解决这个问题，具体代码如下：

class Solution {
public:
    bool isLetteOrNumber(char ch)
    {
        return (ch>='0'&&ch<='9')
            ||(ch>='a'&&ch<='z')
            ||(ch>='A'&&ch<='Z');
    }
    
    bool isPalindrome(string s) {
        for(auto& ch:s)
        {
            if(ch>='a'&&ch<='z')
            {
                ch-=32;//如果是小写，则统一转换为大写
            }
        }
        int begin=0;
        int end=s.size()-1;
        while(begin<end)
        {
            while(begin<end&&!isLetteOrNumber(s[begin]))//从前往后走去找一个数字字符或者字母
            {
                begin++;
            }
             while(begin<end&&!isLetteOrNumber(s[end]))//从后往前走去找一个数字字符或者字母
            {
                end--;
            }
            if(s[begin]!=s[end])
            {
                return false;
            }
            else
            {  
                begin++;
                end--;
            }
        }
        return true;  
    }
};