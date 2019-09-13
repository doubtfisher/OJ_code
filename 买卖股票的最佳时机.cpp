题目：
给定一个数组，它的第?i 个元素是一支给定股票第 i 天的价格。

如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。

注意你不能在买入股票前卖出股票。



示例 1:


输入: [7,1,5,3,6,4]

输出: 5

解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
    注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。


示例 2:


输入: [7,6,4,3,1]

输出: 0

解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。



代码实现：
（1）暴力求解
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size=prices.size();
        int max=0;//最大利润
        for(int i=0;i<size;i++)
        {
            int tmp=0;
            for(int j=i+1;j<size;j++)
            {
                if(prices[i]<prices[j])
                {
                    tmp=prices[j]-prices[i];
                    max=max<tmp?tmp:max;
                }
            }
        }
        return max;
    }
};


（2）堆栈法

class Solution {
public:
    int maxProfit(vector<int>& prices) {      
        int size=prices.size();
        int max=0;//最大利润
        stack<int> st;
        st.push(10000);//这里第一个数字不够大的话，会有部分数据放不进去，其实10000是试出来的（捂脸）
        
        for(int i=0;i<size;i++)
        {
            if(prices[i]<st.top())//栈满足先进后出，后面进来的在栈顶，即买入的价格大于卖出的
                st.push(prices[i]);
            else
            {
                int tmp=prices[i]-st.top();
                max=max<tmp?tmp:max;   
            }
                        
        }
        return max;        
    }
};