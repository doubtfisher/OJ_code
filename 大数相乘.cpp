��Ŀ��


ʵ�ִ����˷��������������ַ�����

n1 = '340282366920938463463374607431768211456'
 
n2 = '340282366920938463463374607431768211456' 

��� 
'115792089237316195423570985008687907853269984665640564039457584007913129639936'

Ҫ�󣺲���ʹ�öԴ���������ڽ�֧�ֵ����ԣ���Ҫ�����������ַ����ĺϷ���У�顣

����ʵ�֣�


#include<iostream>
#include<string>

using namespace std;
 
string multiply(string num1, string num2) 
{
    int len1 = num1.size(),len2 = num2.size();
    string res(len1 + len2, '0');
    for (int i = len2 - 1; i >= 0; i--)  //�Ӹ�λ��ʼ��ע�⣺�����ǴӸ�λ����λ�洢�ģ�i+j���i+j+1���Ǹ�λ��
{  
        for (int j = len1 - 1; j >= 0; j--)
{
            int temp = (res[i + j + 1] - '0') + (num1[j] - '0')*(num2[i] - '0');    //res[i + j + 1] - '0',//�п���֮ǰ��λ�ˣ��������ֻ���λӰ��һλ
            res[i + j + 1] = temp % 10 + '0';//��ǰλ.�����ǵ��ڣ�����Ҫ�ӡ�0��
            res[i + j] += temp / 10; //ǰһλ���Ͻ�λ��res[i+j]�Ѿ���ʼ��Ϊ'0'������int�����Զ�ת��Ϊchar�����Դ˴�����'0'
        }
    }
    //ȥ����λ'0'
    for (int i = 0; i<len1 + len2; i++) //�Ӹ�λ����λ��0
        if (res[i] != '0')
            return res.substr(i);//�ӵ�һ������0������ȡ
    return "0";
}

int main() {
    string num1,num2;
    cin >> num1 >> num2;
    cout << multiply(num1, num2)<<endl;
    return 0;
}
