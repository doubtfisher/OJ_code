��Ŀ��
��ֵ 1,5,10,20,50,100Ԫ������ĵ�һ��Ϊ��������ֵ�ĸ����������MԪ�ķ�������Ϊ���
���磺
���룺
6 5 4 3 2 1
11
�����
12
���������ó�����������֣���Ϊ{1 1 1 1 1 1 7 5}��{1 5 5}��{1 10}
����֮��Ϊ7+3+2=11.

����ʵ�֣�
������̬�滮
#include<iostream>
#include<vector>
using namespace std;

//int v[1001] = {0};
//int f[1001] = {0};

struct F
{
    int value;
    int len;
}f[1001];

int main()
{  
    int v[7] = {0, 1, 5, 10, 20, 50, 100 };//��������ֵ��С
    int arr[7] = { 0 };//��ͬ��ֵ�ĸ���
    int m = 0
    while (cin >> arr[1] >> arr[2] >> arr[3] >> arr[4] >> arr[5] >> arr[6])
    {
        cin >> m;
        f[0].value = 1;//��ʼ��
       f[0].len = 0;
        for (int i = 1; i < 1001; i++)
        {
            f[i].value = 0;
           f[i].len = 0;
        }
        for (int i = 1; i <= 6; i++)
        {
            for (int j = m; j >= v[i]; j--)
            {
                for (int k = 1; k <= j / v[i] && k <= arr[i]; k++)
                {
                    if (f[j - k*v[i]].value == 1)
                    {
                        f[j].len += k;
                       f[j].len += f[j - k*v[i]].len;
                    }
                    f[j].value += f[j - k*v[i]].value;
                }
            }
        }
        cout << f[m].value<<" "<<f[m].len << endl;//����������ͷ����ܳ���
    }
    system("pause");
    return 0;
}