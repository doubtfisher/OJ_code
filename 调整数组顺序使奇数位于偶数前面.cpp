//��Ŀ����������˳��ʹ����λ��ż��ǰ��,����ʹԭ�����������ֵ����λ�ò���

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void reOrderArray(vector<int> &array)
	{
		vector<int> tmp;//����һ���µ�vector
		vector<int>::iterator it = array.begin();
		while (it != array.end())
		{
			if (*it % 2 == 0)//�ҵ�һ��ż�����Ͱ����ŵ��µ�vector
			{
				tmp.push_back(*it);
				it = array.erase(it);//ɾ��ԭ�������е�ż��
			}
			else
			{
				it++;
			}
		}
		for (size_t i = 0; i<tmp.size(); i++)//�ٰ��µ�vector�е�����β�嵽ԭ������ĺ���
		{
			array.push_back(tmp[i]);
		}
	}
};