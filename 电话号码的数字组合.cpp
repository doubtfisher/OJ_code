问题：
给定一个仅包含数字?2-9?的字符串，返回所有它能表示的字母组合。给出数字到字母的映射如下（与电话按键相同），注意 1 不对应任何字母。



分析：
这道题是利用多向递归完成的，首先把字符“234”转换为数字234，并找到数字234对应的字母如下图，然后开始让a去和数字3里面对应的第一个字母匹配，再让他们两匹配的结果和4里面的三个字母分别匹配，匹配完后，返回到3中的第二个字母，再让此时的ad和4中的三个字母分别匹配。这样依次类推，直到所有的字母都匹配完毕，并把匹配好的字符串放到vector中即可。


实现代码如下：
class Solution {
public:
    char* num_to_str[10]={" "," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
  
    void combinations(const string& digits,size_t index, vector<string>& strv,const string& combineStr)
    {
        if(index==digits.size())//当递归到最后一层的最后一个字符时，让index再加一次，此时index已访问完毕，这时候把组合好的字符串尾插到strv容器中，并退出当前递归深度，返回上一层的递归处。
        {
            strv.push_back(combineStr);
            return;
        }
        int num=digits[index]-'0';
        string str=num_to_str[num];
        for(auto ch: str)
        {
            combinations(digits,index+1,strv,combineStr+ch);//递归去组合字符串
        }
    }
    
    vector<string> letterCombinations(string digits)
    {
      if(digits.empty())//如果给的是空串，则返回空vector
      {
          return vector<string>();
      }
     size_t index=0;//digits里面给出的字符个数，从0开始数
     vector<string> strv;//存放输出字符串的容器
     string combineStr;//存放组合后的字符串
     combinations(digits,index,strv,combineStr);   
        
        return strv;
    }
};