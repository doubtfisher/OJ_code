题目：


实现大数乘法，输入是两个字符串如

n1 = '340282366920938463463374607431768211456'
 
n2 = '340282366920938463463374607431768211456' 

输出 
'115792089237316195423570985008687907853269984665640564039457584007913129639936'

要求：不能使用对大数相乘有内建支持的语言；需要包含对输入字符串的合法性校验。

代码实现：


#include<iostream>
#include<string>

using namespace std;
 
string multiply(string num1, string num2) 
{
    int len1 = num1.size(),len2 = num2.size();
    string res(len1 + len2, '0');
    for (int i = len2 - 1; i >= 0; i--)  //从个位开始。注意：数组是从高位到低位存储的，i+j相对i+j+1才是高位！
{  
        for (int j = len1 - 1; j >= 0; j--)
{
            int temp = (res[i + j + 1] - '0') + (num1[j] - '0')*(num2[i] - '0');    //res[i + j + 1] - '0',//有可能之前进位了，而且最多只会进位影响一位
            res[i + j + 1] = temp % 10 + '0';//当前位.这里是等于，所以要加‘0’
            res[i + j] += temp / 10; //前一位加上进位！res[i+j]已经初始化为'0'，加上int类型自动转化为char，所以此处不加'0'
        }
    }
    //去除首位'0'
    for (int i = 0; i<len1 + len2; i++) //从高位到低位找0
        if (res[i] != '0')
            return res.substr(i);//从第一个不是0的数截取
    return "0";
}

int main() {
    string num1,num2;
    cin >> num1 >> num2;
    cout << multiply(num1, num2)<<endl;
    return 0;
}
