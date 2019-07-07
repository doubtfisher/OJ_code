题目：
一只青蛙一次可以跳上1级台阶，也可以跳上2级....它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。

分析：
这套题目是斐波那契数列的变形，把n设置为不同的数，找规律：
当n的取值为：  1   2   3   4....
跳台阶的种数 ：1   2   4   8...


代码实现：
class Solution {
public:
    int jumpFloorII(int number) {
      //return 1<<(number-1);
        return pow(2,number-1);
    }
};