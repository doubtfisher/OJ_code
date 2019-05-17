
题目：一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        int size=data.size();
        int index=0,number=0;
       for(int i=0;i<size;i++)//把所有数字异或，最后结果是单独出现的那两个数字异或的结果
       {
           number^=data[i];
       }
       for(index=31;index>=0;index++) 
       {
           if((number&(1<<index))!=0)
           {
               break;
           }
       }
       for(int i=0;i<size;i++)//根据二进制中为1的分组
       {
             if((data[i]&(1<<index))==0)
             {
                 num1[0]^=data[i];
             }
             else
             {
               num2[0]^=data[i];
             }
       }
 }
};