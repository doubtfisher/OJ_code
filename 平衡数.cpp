��Ŀ��

ţţ���о����Լ�������ƽ������ƽ�����Ķ����ǣ���һ�����ֳ����������֣��ֱ��Ϊ�����µ�����
���Ҳ��ֱ��������������㣺
1����ߺ��ұ����ٴ���һλ��
2����ߵ���ÿһλ�����������ұߵ���ÿһλ��ˣ����������Ϊƽ������

���磺1221��������ֳ�12��21�Ļ���1*2=2*1�����1221Ϊƽ�����������磺1236����������Էֳ�123��1*2*3=6������1236Ҳ��ƽ��������1234����������Ҳ������ƽ������


#include <iostream>
#include <vector>
using namespace std;

bool IsBalance(int n)
{
    if(n<10)
        return false;
    
    //1.��������м�λ
    int count=0;
    int tmp=n;
    while(tmp!=0)
    {
        tmp/=10;
        count++;
    }
    //2.�Ѹ��������ɵ�λ����λ���η���vector��
    vector<int> v;
    while(n!=0)
    {
        v.push_back(n%10);
        n/=10;
    }
   
    //3.˫��ѭ������vector���ж��������߳˻��Ƿ����
    bool flag=false;
    int left_mul=1;
    for(int i=0;i<count-1;i++)
    {
        left_mul*=v[i];//��߳˻����
        int right_mul=1;
        for(int j=i+1;j<count;j++)
        {
            right_mul*=v[j];//�ұ߳˻����
        }
        if(left_mul==right_mul)
        {
            flag=true;
            break;
        }
    }
    if(flag)
        return true;
    else
        return false;
}

int main()
{
    int n;
    while(cin>>n)
    {
         if(IsBalance(n))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
   return 0;
}