题目：
给定两个数组，编写一个函数来计算它们的交集。


示例 1:


输入: 
nums1 = [1,2,2,1],
nums2 = [2,2]

输出: [2,2]

示例 2:


输入: nums1 = [4,9,5],
nums2 = [9,4,9,8,4]

输出: [4,9]



思路分析：
双指针，放进去一个元素后第二个数组的指针就要往后一个，防止用到重复元素

代码实现：
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int i=0;
        int j=0;
        vector<int> res;
        while(i<nums1.size()&&j<nums2.size())
        {
            if(nums1[i]<nums2[j])
                i++;
            else if(nums1[i]>nums2[j])
                j++;
            else
            {
                res.push_back(nums1[i]);
                i++;
                j++;
            }
        }
        return res;
    }
};

方法2：使用map映射

代码实现：
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> mp;
        vector<int> res;
        for(int i=0;i<nums1.size();i++)
        {
            mp[nums1[i]]++;
        }
        for(int j=0;j<nums2.size();j++)
        {
            if(mp[nums2[j]]>0)
            {
                res.push_back(nums2[j]);
                mp[nums2[j]]-=1;
            }
        }
        return res;
    }
};
