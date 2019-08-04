题目：
给定一个已按照升序排列的有序数组，找到两个数使得它们相加之和等于目标数。函数应该返回这两个下标值 index1 和 index2，其中 index1?必须小于?index2。
说明:返回的下标值（index1 和 index2）不是从零开始的。你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。


思路分析：
因为输入的是有序数组，通过运用双指针（i是较小数的位置，j是较大数的位置），求头尾两个元素的sum，若sum与target相比太小，i增大，若sum太大，j减小


实现代码：

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        vector<int> v;
        int i=0;
        int j=numbers.size()-1;
        while(i<j)//双指针，若sum太小，i增大，若sum太大，j减小
        {
            int sum=numbers[i]+numbers[j];
            if(sum==target)
            {
                v.push_back(i+1);
                v.push_back(j+1);
                return v;
            }
            else if(sum>target)
            {
                j—;
            }
            else
            {
                i++;
            }
        }
        return  v;
    }
};