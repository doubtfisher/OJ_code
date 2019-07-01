题目：
春节期间小明使用微信收到很多个红包，非常开心。在查看领取红包记录时发现，某个红包金额出现的次数超过了红包总数的一半。请帮小明找到该红包金额。写出具体算法思路和代码实现，要求算法尽可能高效。
给定一个红包的金额数组gifts及它的大小n，请返回所求红包的金额。若没有金额超过总数的一半，返回0。

方法1：
class Gift {
public:
    int getValue(vector<int> gifts, int n) 
    {
        int count=0;
        int ret=0;
        for(int i=0;i<n;i++)
        {
            if(count==0)
            {
                ret=gifts[i];
                count++;
            }
            else
            {
                if(ret==gifts[i])
                {
                    count++;
                }
                else
                {
                    count--;
                }
            }
        }
        int size=0;
        for(int i=0;i<n;i++)
        {
            if(gifts[i]==ret)
            {
                size++;
            }
        }
        return size >=(n/2) ? ret : 0;
    }
};

方法2：
class Gift {
public:
    int getValue(vector<int> gifts, int n) {
        sort(gifts.begin(),gifts.end());//先排序
        int mid=gifts[n/2];//最中间的那个数
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(mid==gifts[i])
                count++;
        }
        return count>n/2?mid:0;
    }
};

方法3：使用map统计次数

class Gift {
public:
    int getValue(vector<int> gifts, int n) {
        map<int,int> count;//定义一个map
        int middle=n/2;
        for(int i=0;i<n;i++)
        {
            count[gifts[i]]++;//加的是second
        }
        for(const auto& e: count)
        {
            if(e.second>=middle)
                return e.first;//返回键值key
        }
        return 0;
    }
};