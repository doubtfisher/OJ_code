//��Ŀ�������ڼ�С��ʹ��΢���յ��ܶ��������ǳ����ġ��ڲ鿴��ȡ�����¼ʱ���֣�ĳ���������//�ֵĴ��������˺��������һ�롣���С���ҵ��ú����д�������㷨˼·�ʹ���ʵ�֣�Ҫ���㷨��//���ܸ�Ч������һ������Ľ������gifts�����Ĵ�Сn���뷵���������Ľ���û�н���������//һ�룬����0��




class Gift {
public:
    int getValue(vector<int> gifts, int n) {
      int tmp;
      int count=0;
      for(size_t i=0;i<n;i++)
      {
          if(count==0)
          {
              count++;
              tmp=gifts[i];
          }
          else
          {
              if(tmp==gifts[i])
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
        for(size_t i=0;i<n;i++)
        {
            if(tmp==gifts[i])
            {
                size++;
            }
        }
       return size>=n/2?tmp:0;
    }
};