//��Ŀ����ά�����еĲ���


#include <iostream>
#include <vector>
using namespace std;
bool Find(int target, vector<vector<int> > array) {
	int row = array.size();
	int col = array[0].size();
	int i = 0, j = col - 1;
	while (i<row&&j >= 0)
	{
		if (array[i][j]<target)
		{
			i++;
		}
		else if (array[i][j] == target)
		{
			return true;
		}
		else if (array[i][j]>target)
		{
			j--;
		}
		else
		{
			return false;
		}
	}
	return false;
}