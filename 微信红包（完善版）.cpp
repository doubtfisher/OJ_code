��Ŀ��
�����ڼ�С��ʹ��΢���յ��ܶ��������ǳ����ġ��ڲ鿴��ȡ�����¼ʱ���֣�ĳ����������ֵĴ��������˺��������һ�롣���С���ҵ��ú����д�������㷨˼·�ʹ���ʵ�֣�Ҫ���㷨�����ܸ�Ч��
����һ������Ľ������gifts�����Ĵ�Сn���뷵���������Ľ���û�н���������һ�룬����0��

����1��
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

����2��
class Gift {
public:
    int getValue(vector<int> gifts, int n) {
        sort(gifts.begin(),gifts.end());//������
        int mid=gifts[n/2];//���м���Ǹ���
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(mid==gifts[i])
                count++;
        }
        return count>n/2?mid:0;
    }
};

����3��ʹ��mapͳ�ƴ���

class Gift {
public:
    int getValue(vector<int> gifts, int n) {
        map<int,int> count;//����һ��map
        int middle=n/2;
        for(int i=0;i<n;i++)
        {
            count[gifts[i]]++;//�ӵ���second
        }
        for(const auto& e: count)
        {
            if(e.second>=middle)
                return e.first;//���ؼ�ֵkey
        }
        return 0;
    }
};