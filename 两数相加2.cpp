��Ŀ��
����һ���Ѱ����������е��������飬�ҵ�������ʹ���������֮�͵���Ŀ����������Ӧ�÷����������±�ֵ index1 �� index2������ index1?����С��?index2��
˵��:���ص��±�ֵ��index1 �� index2�����Ǵ��㿪ʼ�ġ�����Լ���ÿ������ֻ��ӦΨһ�Ĵ𰸣������㲻�����ظ�ʹ����ͬ��Ԫ�ء�


˼·������
��Ϊ��������������飬ͨ������˫ָ�루i�ǽ�С����λ�ã�j�ǽϴ�����λ�ã�����ͷβ����Ԫ�ص�sum����sum��target���̫С��i������sum̫��j��С


ʵ�ִ��룺

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        vector<int> v;
        int i=0;
        int j=numbers.size()-1;
        while(i<j)//˫ָ�룬��sum̫С��i������sum̫��j��С
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
                j��;
            }
            else
            {
                i++;
            }
        }
        return  v;
    }
};