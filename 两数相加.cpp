��Ŀ��
����һ���������� nums?��һ��Ŀ��ֵ target�������ڸ��������ҳ���ΪĿ��ֵ����?����?���������������ǵ������±ꡣ
����Լ���ÿ������ֻ���Ӧһ���𰸡����ǣ��㲻���ظ��������������ͬ����Ԫ�ء�


����һ��
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;
        vector<int> v(2,-1);
        for(int i=0;i<nums.size();i++)
        {
            m.insert(make_pair(nums[i],i));//�����е�������map��
        }
        for(int i=0;i<nums.size();i++)
        {
            //map.count(Key)����ֵΪ1����0��1���ش��ڣ�0���ز����ڣ����ص��ǲ������͵�ֵ����Ϊ��map���������е����ݵ�Keyֵ���ǲ�ͬ�ģ�
            //���Ա�count����Ҫô����1�Σ�Ҫô������
            if(m.count(target-nums[i])>0&&(m[target-nums[i]]!=i))//�ж��Ƿ��ҵ�Ŀ��Ԫ����Ŀ��Ԫ�ز����Ǳ���
            {
                v[0]=i;
                v[1]=m[target-nums[i]];
                break;
            }
        }
        return v;      
    };
};


��������
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)//�������
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

