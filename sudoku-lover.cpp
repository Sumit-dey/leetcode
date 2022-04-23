class Solution {
public:
    void find_empty( vector<vector<char>>& board, int &x, int &y, vector<bool> &cand )
    {
        x = -1;
        y = -1;
        for( int i = 0; i < 9 and x == -1; i++ )
        {
            for( int j = 0; j < 9; j++ )
            {
                if( board[i][j] == '.' )
                {
                    x = i;
                    y = j;
                    break;
                }
            }
        }
        if( x == -1 )
            return;
        for( int i = 0; i < 9; i++ )
        {
            if( board[x][i] != '.' )
            {
                int d = board[x][i] - '0';
                cand[d] = false;
            }
        }
        for( int i = 0; i < 9; i++ )
        {
            if( board[i][y] != '.' )
            {
                int d = board[i][y] - '0';
                cand[d] = false;
            }
        }
        int bigx = (x/3)*3, bigy = (y/3)*3;
        for( int i = 0; i < 3; i++ )
        {
            for( int j = 0; j < 3; j++ )
            {
                if( board[bigx+i][bigy+j] != '.' )
                {
                    int d = board[bigx+i][bigy+j] - '0';
                    cand[d] = false;
                }
            }
        }
        return;
    }

    bool solve( vector<vector<char>>& board )
    {
        int x, y;
        vector<bool> candidate(10, true);
        find_empty(board, x, y, candidate);
        if( x == -1 )
        {
            return true;
        }
        for( int i = 1; i <= 9; i++  )
        {
            if( candidate[i] == true )
            {
                board[x][y] = i + '0';
                bool f = solve( board );
                if( f )
                    return f;
                board[x][y] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
