题目：统计一个数字在排序数组中出现的次数。

时间复杂度为O(N)的方法：
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int count =0;
        for(int i=0;i<data.size();i++)
        {
            if(data[i]==k)
            {
                count++;
            }
        }
        return count;
    }
};