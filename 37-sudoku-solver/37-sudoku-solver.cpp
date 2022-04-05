class Solution {
public:
    
    bool isSafe(vector<vector<char>>& board, int i, int j, char num)
    {
        for(int m = 0; m < 9; m++)
        {
            if(board[i][m] == num) return false;
            if(board[m][j] == num) return false;
            if(board[3 * (i/3) + m/3][3 * (j/3) + m%3] == num) return false; // Formula
        }
        return true;
    }

    bool solve(vector<vector<char>>& board, int row, int col)
    {
        
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(board[i][j] == '.')
                {
                    for(char num = '1'; num <= '9'; num++)
                    {
                        if(isSafe(board, i, j, num)) 
                        {
                            board[i][j] = num;
                            if(solve(board, row, col)) 
                            {
                                cout << "hi" << " ";
                                return true;
                            }
                            else
                            {
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) 
    {
        int row = board.size();
        if(!row) return;
        int col = board[0].size();
        solve(board, row, col);
    }
};