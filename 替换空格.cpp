��Ŀ����ʵ��һ����������һ���ַ����е�ÿ���ո��滻�ɡ�%20�������磬���ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���ΪWe%20Are%20Happy��


����1��

class Solution {
public:
	void replaceSpace(char *str,int length) {
      int count=0;
      for(int i=0;i<length;i++)//ͳ�ƿո�ĸ���
      {
          if(str[i]==' ')
          {
              count++;
          }
      }
      int newlength=length+2*count;//
      char* index=str+length;//�ַ���index����ָ��ԭ���ַ��������һ���ַ�
        while(index>=str)//���ű���
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


����2��
��תΪstring,������ɺ���תΪchar *���������Է���ֵ����ʽ����Ҫ���ú�ԭ���Ŀռ䣬��strcpyʵ�ִ������ѭ�����ң�ÿ���ҵ����滻���Ұ�ÿ�ε��ҵ��Ľ��������һ�εĲ����������ظ���ͷ���ҡ�

class Solution {
public:
    
	void replaceSpace(char *str,int length) 
    {
       string s(str);
       size_t i=0;
        while((i=s.find(' ',i))!=s.npos)//ѭ�����ҿո�
        {
            s.erase(i,1);��//�ѿո�ɾ��
            s.insert(i,"%20");//�ٰ���Ҫ���ַ������ȥ
        }
        const char* ret=s.c_str();
        strcpy(str,ret);
	}
};

