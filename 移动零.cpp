��Ŀ��
����һ������ nums����дһ������������ 0 �ƶ��������ĩβ��ͬʱ���ַ���Ԫ�ص����˳��

˼·������
�������飬ֻҪ����0��ɾ����count��1����0�ĸ������������ĩβ����count��0���ɡ���Ϊʹ���˵�������Ҫע����Ǳ��������ʧЧ��

����ʵ�֣�

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count=0;//ͳ��0�ĸ���
        auto it=nums.begin();
        while(it!=nums.end())
        {
            if(*it==0)
            {
                it=nums.erase(it);
                count++;
            }
            else
            {
                it++;
            }
        }
        nums.insert(nums.end(),count,0);//��β�Ͻ��в���
    }
};