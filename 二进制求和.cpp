题目：
给定两个二进制字符串，返回他们的和（用二进制表示）。

输入为非空字符串且只包含数字?1?和?0。


示例?1:


输入:
 a = "11", b = "1"

输出: "100"

示例?2:


输入: a = "1010", b = "1011"

输出: "10101"

思路实现：这道题实现与两个字符串相加有点像，只是进位的条件不一样而已。

代码实现：
class Solution {
public:
    string addBinary(string a, string b) {
        int end1=a.size()-1;
        int end2=b.size()-1;
        int val1=0,val2=0;
        string ret;
        int sumret=0;
        int next=0;
        while(end1>=0||end2>=0)
        {
            if(end1>=0)
                val1=a[end1--]-'0';
            else
                val1=0;
            if(end2>=0)
                val2=b[end2--]-'0';
            else
                val2=0;
            
            sumret=val1+val2+next;
            if(sumret>=2)
            {
                next=1;
                sumret-=2;
            }
            else
                next=0;
            
            ret+=(sumret+'0');
        }
        if(next==1)
        {
            ret+='1';
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
};