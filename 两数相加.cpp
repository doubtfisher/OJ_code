题目：
给定一个整数数组 nums?和一个目标值 target，请你在该数组中找出和为目标值的那?两个?整数，并返回他们的数组下标。
你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。


方法一：
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;
        vector<int> v(2,-1);
        for(int i=0;i<nums.size();i++)
        {
            m.insert(make_pair(nums[i],i));//把所有的数放入map中
        }
        for(int i=0;i<nums.size();i++)
        {
            //map.count(Key)返回值为1或者0，1返回存在，0返回不存在，返回的是布尔类型的值，因为在map类型中所有的数据的Key值都是不同的，
            //所以被count的数要么存在1次，要么不存在
            if(m.count(target-nums[i])>0&&(m[target-nums[i]]!=i))//判断是否找到目标元素且目标元素不能是本身
            {
                v[0]=i;
                v[1]=m[target-nums[i]];
                break;
            }
        }
        return v;      
    };
};


方法二：
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)//暴力求解
    {
        vector<int> v(2,-1);
    for(int i=0;i<nums.size();i++)
    {
        for(int j=i+1;j<nums.size();j++)
        {
            if(nums[j]==target-nums[i])
            {
                v[0]=i;
                v[1]=j;
                break;
            }
        }
    }
    return v;       
    }
};

