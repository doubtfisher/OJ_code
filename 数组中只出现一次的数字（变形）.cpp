
��Ŀ��һ�����������������������֮�⣬���������ֶ����������Ρ���д�����ҳ�������ֻ����һ�ε�����

����ʵ�֣�

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int size=nums.size();
        int num=0;
        int index=0;
        int v1=0;
        int v2=0;
        for(int i=0;i<size;i++)//�������������������ǵ������ֵ��������������Ľ��
        {
            num^=nums[i];
        }
        for(index=0;index<32;index++)
        {
            if((num&(1<<index))!=0)//��1������
                break;
        }
        for(int i=0;i<size;i++)//����ԭ����
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

  �����⣺ ����a��ֻ��һ��������һ�Σ���������������2�Σ��ҳ�������֣���javaд�ģ�

    public static int find1From2(int[] a){
        int len = a.length, res = 0;
        for(int i = 0; i < len; i++){
            res = res ^ a[i];
        }
        return res;
    }

�����⣺ ����a��ֻ��һ��������һ�Σ��������ֶ�������3�Σ��ҳ��������


��1��ʹ��map���ݽṹ���м��㣺

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
        return -1;*/  //���ֱ�����ʽ����
        map<int, int>::iterator it;
		for (it = mp.begin(); it != mp.end(); it++)
		{
			if (it->second == 1)
				return it->first;
		}
		return -1;
    }
};

��2��

       
        }
        return res;
    }