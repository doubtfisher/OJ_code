//题目：求连续子数组的最大和

#include <iostream>
#include <vector>
using namespace std;

int FindGreatestSumOfSubArray(vector<int> array)
{
	int sum = array[0];
	int maxsum = array[0];
	for (size_t i = 1; i<array.size(); i++)
	{
		if (sum >= 0)
		{
			sum += array[i];
		}
		else
		{
			sum = array[i];
		}
		if (maxsum<sum)
		{
			maxsum = sum;
		}
	}
	return maxsum;
}
