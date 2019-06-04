题目：
对于一个给定的井字棋棋盘，请设计一个高效算法判断当前玩家是否获胜。给定一个二维数组board，代表当前棋盘，其中元素为1的代表是当前玩家的棋子，为0表示没有棋子，为-1代表是对方玩家的棋子。


class Board {
public:
    bool checkWon(vector<vector<int> > board) 
    {
       int row=board.size();
       //1.判断行的和
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
        //2.判断列的和
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
        //3.判断主对角线的和
        int sum=0;
        for(int i=0;i<row;i++)
        {
            sum+=board[i][i];
        }
        if(sum==row)
            return true;
        
        //4.判断副对角线的和
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