题目：
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

思路分析：
遍历数组，只要遇到0则删除，count加1（计0的个数），最后在末尾补上count个0即可。因为使用了迭代器，要注意的是避免迭代器失效。

代码实现：

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count=0;//统计0的个数
        auto it=nums.begin();
        while(it!=nums.end())
        {
            if(*it==0)
            {
                it=nums.erase(it);
                count++;
            }
            else
            {
                it++;
            }
        }
        nums.insert(nums.end(),count,0);//在尾上进行插入
    }
};