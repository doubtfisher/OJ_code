���⣺
����һ������������?2-9?���ַ����������������ܱ�ʾ����ĸ��ϡ��������ֵ���ĸ��ӳ�����£���绰������ͬ����ע�� 1 ����Ӧ�κ���ĸ��



������
����������ö���ݹ���ɵģ����Ȱ��ַ���234��ת��Ϊ����234�����ҵ�����234��Ӧ����ĸ����ͼ��Ȼ��ʼ��aȥ������3�����Ӧ�ĵ�һ����ĸƥ�䣬����������ƥ��Ľ����4�����������ĸ�ֱ�ƥ�䣬ƥ����󣬷��ص�3�еĵڶ�����ĸ�����ô�ʱ��ad��4�е�������ĸ�ֱ�ƥ�䡣�����������ƣ�ֱ�����е���ĸ��ƥ����ϣ�����ƥ��õ��ַ����ŵ�vector�м��ɡ�


ʵ�ִ������£�
class Solution {
public:
    char* num_to_str[10]={" "," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
  
    void combinations(const string& digits,size_t index, vector<string>& strv,const string& combineStr)
    {
        if(index==digits.size())//���ݹ鵽���һ������һ���ַ�ʱ����index�ټ�һ�Σ���ʱindex�ѷ�����ϣ���ʱ�����Ϻõ��ַ���β�嵽strv�����У����˳���ǰ�ݹ���ȣ�������һ��ĵݹ鴦��
        {
            strv.push_back(combineStr);
            return;
        }
        int num=digits[index]-'0';
        string str=num_to_str[num];
        for(auto ch: str)
        {
            combinations(digits,index+1,strv,combineStr+ch);//�ݹ�ȥ����ַ���
        }
    }
    
    vector<string> letterCombinations(string digits)
    {
      if(digits.empty())//��������ǿմ����򷵻ؿ�vector
      {
          return vector<string>();
      }
     size_t index=0;//digits����������ַ���������0��ʼ��
     vector<string> strv;//�������ַ���������
     string combineStr;//�����Ϻ���ַ���
     combinations(digits,index,strv,combineStr);   
        
        return strv;
    }
};