题目：数组中出现次数超过一半的数字

//数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组//{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出//0。

方法1：先排序，如果出现次数超过一半，则最中间的那个数肯定是出现次数超过一半的数。

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
方法2：如果有符合条件的数字，则它出现的次数比其他所有数字出现的次数和还要多。在遍历数组时保存两个值：一是数组中一个数字，一是次数。遍历下一个数字时，若它与之前保存的数字相同，则次数加1，否则次数减1；若次数为0，则保存下一个数字，并将次数置为1。遍历结束后，所保存的数字即为所求。然后再判断它是否符合条件即可。

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