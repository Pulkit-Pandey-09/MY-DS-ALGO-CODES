class Solution {
public:
    
    bool isSafe(int row, int col, vector<string> &board, int n)
    {
        int duprow = row;
        int dupcol = col;
        
        while(duprow >= 0 && dupcol >= 0)
        {
            if(board[duprow][dupcol] == 'Q') return false;
            duprow--;
            dupcol--;
        }
        
        duprow = row;
        dupcol = col;
        while(duprow < n && dupcol >= 0)
        {
            if(board[duprow][dupcol] == 'Q') return false;
            duprow++;
            dupcol--;
        }
        
        duprow = row;
        dupcol = col;
        while(col >= 0)
        {
            if(board[row][col] == 'Q') return false;
            col--;
        }
        return true;
    }
    
    void solve(vector<string> &board, vector<vector<string>> &ans, int n, int col)
    {
        if(col == n)
        {
            ans.push_back(board);
            return;
        }
        
        for(int row = 0; row < n; row++)
        {
            if(isSafe(row, col, board, n))
            {
                board[row][col] = 'Q';
                solve(board, ans, n, col+1);
                board[row][col] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for(int i = 0; i < n; i++)
        {
            board[i] = s;
        }
        solve(board, ans, n, 0);
        return ans;
    }
};