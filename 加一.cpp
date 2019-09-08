题目：
给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。


示例?1:


输入: [1,2,3]

输出: [1,2,4]

解释: 输入数组表示数字 123。


示例?2:


输入: [4,3,2,1]

输出: [4,3,2,2]

解释: 输入数组表示数字 4321。

思路分析：
对于一般的数字，直接在末位加一即可，若加一之后的值为10，需要进一位

若数字为类似999 ，加一之后需要多一位数。使用insert()来实现， insert函数 ： vec.insert(begin()+i ,a) 在第i个元素插入a

。

代码实现：
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int end=digits.size()-1;
        if(digits[end]!=9) //若末位等于9，加一等于0
            digits[end]++;
        else
        {
          digits[end]=0;
          for(int i=end;i>0;i--)//若加完一后若等于0，下一位要进一 如869
           {
              if(digits[i]==0)
              {
                  digits[i-1]=(digits[i-1]+1)%10;
              }
              else
                  break; //若某一位是数不需要进一，跳出循环
           }
        }
        if(digits[0]==0)//若到最后最高位也等于0，需要多一位数 如99 + 1  此时为答案为00
            digits.insert(digits.begin(),1);//在第一个数之前插入1
        return digits;
    }
};