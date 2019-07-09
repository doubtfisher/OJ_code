题目：
写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。

思路：
1. 两个数异或：相当于每一位相加，而不考虑进位；
2. 两个数相与，并左移一位：相当于求得进位；
3. 将上述两步的结果相加
循环处理，直到没有进位

实现代码如下：

class Solution {
public:
    int Add(int num1, int num2)
    {
        while(num1)//判断进位是否为0
        {
            //1.计算各位的和
            int tmp=num1^num2;
            //2.计算进位
            num1=(num1&num2)<<1;
            num2=tmp;
        }
        return num2;
    }
};