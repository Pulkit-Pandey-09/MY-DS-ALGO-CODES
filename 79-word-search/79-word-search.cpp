class Solution {
public:
    
    vector<vector<int>> offSet = {{1,0} , {-1,0}, {0,1}, {0,-1}};
    
    bool okay(vector<vector<char>>& board, string word, vector<vector<int>>& visited, int r, int c, int i, int j, int p)
    {
        return i >= 0 && i < r && j >= 0 && j < c && visited[i][j] == 0 && board[i][j] == word[p];
    }
    
    bool solve(vector<vector<char>>& board, string word, vector<vector<int>>& visited, int r, int c, int i, int j, int p, int ws)
    {
        if(p == ws-1) return true;
        if(i < 0 || i >= r || j < 0 || j >= c || visited[i][j]) return false;
        visited[i][j] = 1;
        bool ans = false;
        for(int m = 0; m < 4; m++)
        {
            int idx = i + offSet[m][0];
            int idy = j + offSet[m][1];
            if(okay(board, word, visited, r, c, idx, idy, p+1))
            {
                ans = ans || solve(board, word, visited, r, c, idx, idy, p+1, ws);
            }
        }
        visited[i][j] = 0;
        return ans;
    }
    
    bool exist(vector<vector<char>>& board, string word) 
    {
        int r = board.size();
        int c = board[0].size();
        int ws = word.size();
        vector<vector<int>> visited(r, vector<int>(c, 0));
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                if(board[i][j] == word[0] && solve(board, word, visited, r, c, i, j, 0, ws))
                {
                    return true;
                }
            }
        }
        return false;
    }
};