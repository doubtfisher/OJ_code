题目：请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。


方法1：

class Solution {
public:
	void replaceSpace(char *str,int length) {
      int count=0;
      for(int i=0;i<length;i++)//统计空格的个数
      {
          if(str[i]==' ')
          {
              count++;
          }
      }
      int newlength=length+2*count;//
      char* index=str+length;//字符串index现在指向原来字符串的最后一个字符
        while(index>=str)//倒着遍历
        {
            if(*index!=' ')
            {
                str[newlength--]=*index;
            }
            else
            {
                str[newlength--]='0';
                str[newlength--]='2';
                str[newlength--]='%';
            }
            index--;
        }
	}
};


方法2：
先转为string,处理完成后，再转为char *。但不是以返回值的形式，还要利用好原来的空间，用strcpy实现处理过程循环查找，每次找到就替换，且把每次的找到的结果当成下一次的参数，避免重复从头查找。

class Solution {
public:
    
	void replaceSpace(char *str,int length) 
    {
       string s(str);
       size_t i=0;
        while((i=s.find(' ',i))!=s.npos)//循环查找空格
        {
            s.erase(i,1);、//把空格删除
            s.insert(i,"%20");//再把需要的字符插入进去
        }
        const char* ret=s.c_str();
        strcpy(str,ret);
	}
};

