问题：
给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。要求时间复杂度为O(N).



分析：
因为字符串的范围是确定的，所以我们可以先遍历一遍，统计出每个字符出现的次数，然后再遍历一遍看哪个字符只出现了一次，这样不仅可以找出来，而且时间复杂度为O(N).



具体代码如下：

class Solution {
public:
    int firstUniqChar(string s) {
        int countarray[26]={0};
	for (auto ch:s)//统计每个字符出现的次数
	{
		countarray[ch-'a']++;
	}
    for(size_t i=0;i<s.size();i++)
    {
            if(countarray[s[i]-'a']==1)
            {
                return i;
            }
    }
       return -1; 
    }
};