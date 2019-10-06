��Ŀ��
�����������飬��дһ���������������ǵĽ�����


ʾ�� 1:


����: 
nums1 = [1,2,2,1],
nums2 = [2,2]

���: [2,2]

ʾ�� 2:


����: nums1 = [4,9,5],
nums2 = [9,4,9,8,4]

���: [4,9]



˼·������
˫ָ�룬�Ž�ȥһ��Ԫ�غ�ڶ��������ָ���Ҫ����һ������ֹ�õ��ظ�Ԫ��

����ʵ�֣�
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

����2��ʹ��mapӳ��

����ʵ�֣�
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
