��Ŀ��С��������һ��ʯ��·ǰ��ÿ��ʯ���ϴ�1���ű��Ϊ��1��2��3.......
����ʯ��·Ҫ��������Ĺ������ǰ��������С�׵�ǰ���ڵı��ΪK�� ʯ�壬С�׵���ֻ����ǰ��K��һ��Լ��(����1��K)����������K+X(XΪK��һ����1�ͱ����Լ��)��λ�á� С�׵�ǰ���ڱ��ΪN��ʯ�壬�����������ǡ��ΪM��ʯ��ȥ��С����֪��������Ҫ��Ծ���ο��Ե��


������
��1 - M��ʯ�忴��һ���������stepNum��ÿ��stepNum[i]�����Ŵ���㵽��һ����С�Ĳ���������0Ϊ���ܵ��
����㿪ʼ��stepNum���б���������i������Լ��������stepNum[i]���ߵĲ�������
Ȼ������Ǽ����ܵ����λ�õ���С����.������ܵ��������Ϊ��ʱλ�õ���С���� + 1��
������ܵ���ľ͸���Ϊmin���Ѽ�¼����С�������˴�����С���� + 1����������һ���õ������


#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

void NumberFactor(int n,vector<int> &v)
{
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            v.push_back(i);
            if(n/i!=i)
                v.push_back(n/i);
        }
    }
}

int Jump(int n,int m)
{
    vector<int> step(m+1,0);//һ��ʼ�������е�ֵȫ����ʼ��Ϊ0
     step[n]=1;//step���±��Ӧ��ֵ��¼���Ǵ���
    for(int i=n;i<m;i++)
    {
        vector<int> v;//�����һ����������Լ��������1��������
        //0��������㲻�ܵ�
        if(step[i]==0)
            continue;
        
        NumberFactor(i,v);
        
        for(int j=0;j<v.size();j++)
        {
            //��λ��i�����ܵ���ĵ�Ϊ step[v[j]+i]
            if((v[j]+i) <= m && step[v[j]+i]!=0)
            {
                step[v[j]+i]=min(step[v[j]+i],step[i]+1);
            }
            else if((v[j]+i)<= m)
            {
                step[v[j]+i]=step[i]+1;
            }
        }
    }
    if(step[m]==0)
        return -1;
    else
        return step[m]-1;//��ʼ��ʱ�����һ��������Ҫ��1
}

int main()
{
    int n,m;
    cin>>n>>m;
    cout<<Jump(n,m)<<endl;
}


