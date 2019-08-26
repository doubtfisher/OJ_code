题目：

编写一个算法来判断一个数是不是“快乐数”。

一个“快乐数”定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复这个过程直到这个数变为 1，也可能是无限循环但始终变不到 1。如果可以变为 1，那么这个数就是快乐数。



代码实现：
class Solution {
public:
    bool isHappy(int n) {
      
        unordered_set<int> s;
        int t;
        while (n!=1)
        {
            t = n;
            n = 0;
            while (t)
            {
                n += (t % 10) * (t % 10);
                t = t / 10;
            }
            if (s.count(n) != 0)//出现重复的数
                return false;
            s.insert(n);
        }
        return true;
    }
};



