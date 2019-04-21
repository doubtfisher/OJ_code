//题目：调整数组顺序使奇数位于偶数前面,并且使原来数组中数字的相对位置不变

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void reOrderArray(vector<int> &array)
	{
		vector<int> tmp;//创建一个新的vector
		vector<int>::iterator it = array.begin();
		while (it != array.end())
		{
			if (*it % 2 == 0)//找到一个偶数，就把它放到新的vector
			{
				tmp.push_back(*it);
				it = array.erase(it);//删掉原来数组中的偶数
			}
			else
			{
				it++;
			}
		}
		for (size_t i = 0; i<tmp.size(); i++)//再把新的vector中的数据尾插到原来数组的后面
		{
			array.push_back(tmp[i]);
		}
	}
};