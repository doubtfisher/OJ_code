
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

  �����⣺ ����a��ֻ��һ��������һ�Σ���������������2�Σ��ҳ��������

    public static int find1From2(int[] a){
        int len = a.length, res = 0;
        for(int i = 0; i < len; i++){
            res = res ^ a[i];
        }
        return res;
    }

�����⣺ ����a��ֻ��һ��������һ�Σ��������ֶ�������3�Σ��ҳ��������

    public static int find1From3(int[] a){
        int[] bits = new int[32];
        int len = a.length;
        for(int i = 0; i < len; i++){
            for(int j = 0; j < 32; j++){
                bits[j] = bits[j] + ( (a[i]>>>j) & 1);
            }
        }
        int res = 0;
        for(int i = 0; i < 32; i++){
            if(bits[i] % 3 !=0){
                res = res | (1 << i);
            }
        }
        return res;
    }