��Ŀ��
����һ�������ľ��������̣������һ����Ч�㷨�жϵ�ǰ����Ƿ��ʤ������һ����ά����board������ǰ���̣�����Ԫ��Ϊ1�Ĵ����ǵ�ǰ��ҵ����ӣ�Ϊ0��ʾû�����ӣ�Ϊ-1�����ǶԷ���ҵ����ӡ�


class Board {
public:
    bool checkWon(vector<vector<int> > board) 
    {
       int row=board.size();
       //1.�ж��еĺ�
        for(int i=0;i<row;i++)
        {
            int sum=0;
            for(int j=0;j<row;j++)
            {
                 sum+=board[i][j];
            }
            if(sum==row)
                return true;
        }
        //2.�ж��еĺ�
        for(int i=0;i<row;i++)
        {
            int sum=0;
            for(int j=0;j<row;j++)
            {
                sum+=board[j][i];
            }
            if(sum==row)
                return true;
        }
        //3.�ж����Խ��ߵĺ�
        int sum=0;
        for(int i=0;i<row;i++)
        {
            sum+=board[i][i];
        }
        if(sum==row)
            return true;
        
        //4.�жϸ��Խ��ߵĺ�
         sum=0;
        for(int i=0;i<row;i++)
        {
            sum+=board[i][row-1-i];
        }
        if(sum==row)
            return true;
       
       return false;
    }
};