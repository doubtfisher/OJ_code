��Ŀ������
���1~13��������1���ֵĴ���,�����100~1300��������1���ֵĴ�����Ϊ�����ر�����һ��1~13�а���1��������1��10��11��12��13��˹�����6��,���Ƕ��ں�����������û���ˡ�ACMerϣ�����ǰ����,������������ձ黯,���Ժܿ���������Ǹ�����������1���ֵĴ�������1 �� n ��1���ֵĴ�����

����1��ʱ�临�Ӷ�ΪO(nlogn)

class Solution {
public:
    int Count(int n)
    {
        int count=0;
        while(n)
        {
            if(n%10==1)
            {
                count++;
            }
            n=n/10;
        }
        return count;
    }
    
    int NumberOf1Between1AndN_Solution(int n)
    {
         int number=0;
        for(int i=1;i<=n;i++)
        {
            number+=Count(i);
        }
        return number;
    }
};


//����2��ʱ�临�Ӷ�ΪO(logn)





