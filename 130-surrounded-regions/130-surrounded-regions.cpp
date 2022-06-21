class Solution {
public:
    
    vector<vector<int>> offSet = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    
    bool okay(vector<vector<char>>& board, int r, int c, int i, int j)
    {
        return i >= 0 && i < r && j >= 0 && j < c && board[i][j] == 'O';
    }
    
    void dfs(vector<vector<char>>& board, int r, int c, int i, int j)
    {
        if(i < 0 || i >= r || j < 0 || j > c) return;
        board[i][j] = 'V';
        for(int k = 0; k < 4; k++)
        {
            int idx = i + offSet[k][0];
            int idy = j + offSet[k][1];
            if(okay(board, r, c, idx, idy))
            {
                dfs(board, r, c, idx, idy);
            }
        }
        return;
    }
    
    void solve(vector<vector<char>>& board) 
    {
        int r = board.size();
        if(!r) return;
        int c = board[0].size();
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                if(i == 0 || i == r-1 || j == 0 || j == c-1)
                {
                    if(board[i][j] == 'O')
                    {
                        dfs(board, r, c, i, j);
                    }
                }
            }
        }
        
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                if(board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
                else if(board[i][j] == 'V')
                {
                    board[i][j] = 'O';
                }
            }
        }
    }
};