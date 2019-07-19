题目：


所谓因子分解，就是把给定的正整数a，分解成若干个素数的乘积，即 a = a1 × a2 × a3 × ... × an,并且 1 < a1 ≤ a2 ≤ a3 ≤ ... ≤ an。其中a1、a2、...、an均为素数。 先给出一个整数a，请输出分解后的因子。


代码实现：
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