
//��������

//һ�黨������������Щͼ��������һ��ֱ�ӿ��õ�С����������Ҳ��һЩͼ�������ڸ����Ļ�������С������
//����һ���ܴӻ������о����ܼ�������С�������أ�ÿ�����ݰ��������ַ���s, t���ֱ��ǳɶԳ��ֵĻ���
//����С�������䲼�������ÿɼ�ASCII�ַ���ʾ�ģ��ɼ���ASCII�ַ��ж��ٸ��������Ļ���Ҳ�ж����ֻ�����
//��������С�������ᳬ��1000���ַ�����


#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s, t;
	while (cin >> s >> t)
	{
		size_t pos = s.find(t, 0);
		int ret = 0;
		while (pos != string::npos)
		{
			ret++;
			pos = s.find(t, pos + t.size());
		}
		cout << ret << endl;
	}
}