��Ŀ��


��ν���ӷֽ⣬���ǰѸ�����������a���ֽ�����ɸ������ĳ˻����� a = a1 �� a2 �� a3 �� ... �� an,���� 1 < a1 �� a2 �� a3 �� ... �� an������a1��a2��...��an��Ϊ������ �ȸ���һ������a��������ֽ������ӡ�


����ʵ�֣�
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    while(cin >> n)
    {
        printf("%d =", n);
        for(size_t i = 2; i <= sqrt(n); i++)
        {
            while(n != i && n % i == 0)
            {
                printf(" %u *", i);
                n /= i;
            }
        }
        printf(" %d\n",n);
    }
    return 0;
}