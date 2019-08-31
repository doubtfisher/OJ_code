题目：
给定一个包含 n 个整数的数组?nums，判断nums中是否存在三个元素 a，b，c ，使得?a + b + c = 0 ？找出所有满足条件且不重复的三元组。



思路分析（借鉴一位大佬的思路）：

通过双指针动态消去无效解来优化效率。

双指针法铺垫： 先将给定 nums 排序，复杂度为 O(NlogN)O(NlogN)


双指针法思路： 固定 3个指针中最左（最小）数字的指针 k，双指针 i，j 分设在数组索引 (k, len(nums))(k,len(nums)) 两端，通过双指针交替向中间移动，记录对于每个固定指针 k 的所有满足 nums[k] + nums[i] + nums[j] == 0 的 i,j 组合：


当 nums[k] > 0 时直接break跳出：因为 nums[j] >= nums[i] >= nums[k] > 0，即 3 个数字都大于 0 ，在此固定指针 k 之后不可能再找到结果了。


当 k > 0且nums[k] == nums[k - 1]时即跳过此元素nums[k]：因为已经将 nums[k - 1] 的所有组合加入到结果中，本次双指针搜索只会得到重复组合。


i，j 分设在数组索引 (k, len(nums))(k,len(nums)) 两端，当i < j时循环计算s = nums[k] + nums[i] + nums[j]，并按照以下规则执行双指针移动：

当s < 0时，i += 1并跳过所有重复的nums[i]；

当s > 0时，j -= 1并跳过所有重复的nums[j]；

当s == 0时，记录组合[k, i, j]至res，执行i += 1和j -= 1并跳过所有重复的nums[i]和nums[j]，防止记录到重复组合。


复杂度分析：


时间复杂度 O(N^2)O(N 
2
 )：其中固定指针k循环复杂度 O(N)O(N)，双指针 i，j 复杂度 O(N)O(N)。


空间复杂度 O(1)O(1)：指针使用常数大小的额外空间。




实现代码如下：

（1）使用三层for循环暴力求解，会超时，代码如下

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size()<3)
            return {};
        vector<vector<int>> res;//存放结果
        set<vector<int>> ret;//用来去重
        int size=nums.size();
        //三重循环依次遍历
        for(int i=0;i<size-2;i++)
        {
            for(int j=i+1;j<size-1;j++)
            {
                for(int k=j+1;k<size;k++)
                {
                    if(nums[i]+nums[j]+nums[k]==0)
                    {
                        vector<int> tmp;//存放每一次符合要求的结果
                        int a=(nums[i]<nums[j]?nums[i]:nums[j])<nums[k]?(nums[i]<nums[j]?nums[i]:nums[j]):nums[k];//找最小的元素
                        int b=(nums[i]>nums[j]?nums[i]:nums[j])>nums[k]?(nums[i]>nums[j]?nums[i]:nums[j]):nums[k];//找最大的元素        
                        int c=-(a+b);
                        tmp.push_back(a);
                        tmp.push_back(c);
                        tmp.push_back(b);
                        ret.insert(tmp);//放入set，如果出现重复结果，则不会放进去
                    }
                }
            }
        }
        for(auto it:ret)
            res.push_back(it);
        return res;
    }
};

（2）使用排序+双指针

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      sort(nums.begin(),nums.end());//排序
        
      if(nums.size()<3||nums.front()>0||nums.back()<0)//元素个数小于3或者排序之后的第一个元素大于0或最后一个元素小于0
          return {};
        vector<vector<int>> res;//存放最终结果
        int size=nums.size();
        for(int i=0;i<size;i++)
        {
            int fix=nums[i];//固定一个数
            if(fix>0)//第一个数如果大于0.则直接跳出
                break;
            
            if(i>0&&fix==nums[i-1])//去重
                continue;
            int left=i+1;//固定一个数之后，从下一个数开始查找
            int right=size-1;
            while(left<right)//双指针
            {
                if(-fix==nums[left]+nums[right])//符合条件
                {
                    if(left==i+1||right==size-1)
                    {
                        res.push_back(vector<int>{nums[i],nums[left],nums[right]});
                        left++;
                        right--;
                    }
                    else if(nums[left]==nums[left-1])
                        left++;
                    else if(nums[right]==nums[right+1])
                        right--;
                    else
                    {
                        res.push_back(vector<int>{nums[i],nums[left],nums[right]});
                        left++;
                        right--;
                    }
                }
                else if(-fix>nums[left]+nums[right])
                    left++;
                else
                    right--;       
            }
        }
        return res; 
    }
};
