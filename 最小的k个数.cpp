#include <iostream>
#include <vector>

vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
	vector<int> v;
	sort(input.begin(), input.end());
	if (input.size()<k)
	{
		return v;
	}
	for (int i = 0; i<k; i++)
	{
		v.push_back(input[i]);
	}
	return v;
}