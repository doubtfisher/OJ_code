��Ŀ�������г��ִ�������һ�������

//��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡���������һ������Ϊ9������//{1,2,3,2,2,2,5,4,2}����������2�������г�����5�Σ��������鳤�ȵ�һ�룬������2����������������//0��

����1��������������ִ�������һ�룬�����м���Ǹ����϶��ǳ��ִ�������һ�������

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        if(numbers.empty())
            return 0;
        
        sort(numbers.begin(),numbers.end());
        int size=numbers.size();
        int middle=numbers[(size-1)/2];
        int count=0;
        for(size_t i=0;i<numbers.size();i++)
        {
            if(numbers[i]==middle)
             {
                  count++;
             }
         }
        return count>size/2?middle:0;
    }
};
����2������з������������֣��������ֵĴ����������������ֳ��ֵĴ����ͻ�Ҫ�ࡣ�ڱ�������ʱ��������ֵ��һ��������һ�����֣�һ�Ǵ�����������һ������ʱ��������֮ǰ�����������ͬ���������1�����������1��������Ϊ0���򱣴���һ�����֣�����������Ϊ1����������������������ּ�Ϊ����Ȼ�����ж����Ƿ�����������ɡ�

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
     int result,times;
     result=numbers[0];
     times=1;
        for(size_t i=1;i<numbers.size();i++)
        {
           if(times==0)
           {
               result=numbers[i];
               times=1;
           }
           else if(result==numbers[i])
           {
               times++; 
           }
           else
           {
                times--;
           }
        }
        int count=0;
        for(size_t i=0;i<numbers.size();i++)
        {
            if(numbers[i]==result)
            {
                count++;
            }
        }
        return count>numbers.size()/2?result:0;
    }
};