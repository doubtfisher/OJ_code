
��Ŀ��һ�����������������������֮�⣬���������ֶ����������Ρ���д�����ҳ�������ֻ����һ�ε����֡�

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        int size=data.size();
        int index=0,number=0;
       for(int i=0;i<size;i++)//�������������������ǵ������ֵ��������������Ľ��
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
       for(int i=0;i<size;i++)//���ݶ�������Ϊ1�ķ���
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