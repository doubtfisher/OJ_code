
题目：一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字

代码实现：

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int size=nums.size();
        int num=0;
        int index=0;
        int v1=0;
        int v2=0;
        for(int i=0;i<size;i++)//把所有数字异或，最后结果是单独出现的那两个数字异或的结果
        {
            num^=nums[i];
        }
        for(index=0;index<32;index++)
        {
            if((num&(1<<index))!=0)//是1就跳出
                break;
        }
        for(int i=0;i<size;i++)//遍历原数组
        {
            if((nums[i]&(1<<index))==0)
                v1^=nums[i];
            else
                 v2^=nums[i];
        }
        vector<int> v;
        v.push_back(v1);
        v.push_back(v2);
        return v;
    }
};

  变形题： 数组a中只有一个数出现一次，其他数都出现了2次，找出这个数字（用java写的）

    public static int find1From2(int[] a){
        int len = a.length, res = 0;
        for(int i = 0; i < len; i++){
            res = res ^ a[i];
        }
        return res;
    }

变形题： 数组a中只有一个数出现一次，其他数字都出现了3次，找出这个数字


（1）使用map数据结构进行计算：

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        /*for(const auto& e:mp)
        {
            if(e.second==1)
                return e.first;
        }
        return -1;*/  //两种遍历方式都行
        map<int, int>::iterator it;
		for (it = mp.begin(); it != mp.end(); it++)
		{
			if (it->second == 1)
				return it->first;
		}
		return -1;
    }
};

（2）

       
        }
        return res;
    }