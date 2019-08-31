��Ŀ��
����һ������ n ������������?nums���ж�nums���Ƿ��������Ԫ�� a��b��c ��ʹ��?a + b + c = 0 ���ҳ��������������Ҳ��ظ�����Ԫ�顣



˼·���������һλ���е�˼·����

ͨ��˫ָ�붯̬��ȥ��Ч�����Ż�Ч�ʡ�

˫ָ�뷨�̵棺 �Ƚ����� nums ���򣬸��Ӷ�Ϊ O(NlogN)O(NlogN)


˫ָ�뷨˼·�� �̶� 3��ָ����������С�����ֵ�ָ�� k��˫ָ�� i��j �������������� (k, len(nums))(k,len(nums)) ���ˣ�ͨ��˫ָ�뽻�����м��ƶ�����¼����ÿ���̶�ָ�� k ���������� nums[k] + nums[i] + nums[j] == 0 �� i,j ��ϣ�


�� nums[k] > 0 ʱֱ��break��������Ϊ nums[j] >= nums[i] >= nums[k] > 0���� 3 �����ֶ����� 0 ���ڴ˹̶�ָ�� k ֮�󲻿������ҵ�����ˡ�


�� k > 0��nums[k] == nums[k - 1]ʱ��������Ԫ��nums[k]����Ϊ�Ѿ��� nums[k - 1] ��������ϼ��뵽����У�����˫ָ������ֻ��õ��ظ���ϡ�


i��j �������������� (k, len(nums))(k,len(nums)) ���ˣ���i < jʱѭ������s = nums[k] + nums[i] + nums[j]�����������¹���ִ��˫ָ���ƶ���

��s < 0ʱ��i += 1�����������ظ���nums[i]��

��s > 0ʱ��j -= 1�����������ظ���nums[j]��

��s == 0ʱ����¼���[k, i, j]��res��ִ��i += 1��j -= 1�����������ظ���nums[i]��nums[j]����ֹ��¼���ظ���ϡ�


���Ӷȷ�����


ʱ�临�Ӷ� O(N^2)O(N 
2
 )�����й̶�ָ��kѭ�����Ӷ� O(N)O(N)��˫ָ�� i��j ���Ӷ� O(N)O(N)��


�ռ临�Ӷ� O(1)O(1)��ָ��ʹ�ó�����С�Ķ���ռ䡣




ʵ�ִ������£�

��1��ʹ������forѭ��������⣬�ᳬʱ����������

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size()<3)
            return {};
        vector<vector<int>> res;//��Ž��
        set<vector<int>> ret;//����ȥ��
        int size=nums.size();
        //����ѭ�����α���
        for(int i=0;i<size-2;i++)
        {
            for(int j=i+1;j<size-1;j++)
            {
                for(int k=j+1;k<size;k++)
                {
                    if(nums[i]+nums[j]+nums[k]==0)
                    {
                        vector<int> tmp;//���ÿһ�η���Ҫ��Ľ��
                        int a=(nums[i]<nums[j]?nums[i]:nums[j])<nums[k]?(nums[i]<nums[j]?nums[i]:nums[j]):nums[k];//����С��Ԫ��
                        int b=(nums[i]>nums[j]?nums[i]:nums[j])>nums[k]?(nums[i]>nums[j]?nums[i]:nums[j]):nums[k];//������Ԫ��        
                        int c=-(a+b);
                        tmp.push_back(a);
                        tmp.push_back(c);
                        tmp.push_back(b);
                        ret.insert(tmp);//����set����������ظ�������򲻻�Ž�ȥ
                    }
                }
            }
        }
        for(auto it:ret)
            res.push_back(it);
        return res;
    }
};

��2��ʹ������+˫ָ��

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      sort(nums.begin(),nums.end());//����
        
      if(nums.size()<3||nums.front()>0||nums.back()<0)//Ԫ�ظ���С��3��������֮��ĵ�һ��Ԫ�ش���0�����һ��Ԫ��С��0
          return {};
        vector<vector<int>> res;//������ս��
        int size=nums.size();
        for(int i=0;i<size;i++)
        {
            int fix=nums[i];//�̶�һ����
            if(fix>0)//��һ�����������0.��ֱ������
                break;
            
            if(i>0&&fix==nums[i-1])//ȥ��
                continue;
            int left=i+1;//�̶�һ����֮�󣬴���һ������ʼ����
            int right=size-1;
            while(left<right)//˫ָ��
            {
                if(-fix==nums[left]+nums[right])//��������
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
