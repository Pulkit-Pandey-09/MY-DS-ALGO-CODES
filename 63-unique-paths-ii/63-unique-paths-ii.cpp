class Solution {
public:
    
    int solve(vector<vector<int>>& grid, int r, int c, int i, int j, vector<vector<int>> &dp)
    {
        // base case
        if(i >= r || j >= c || grid[i][j] == 1) return 0;
        if(i == r-1 && j == c-1 && grid[i][j] == 0) return 1;
        if(dp[i][j] != -1) return dp[i][j]; 
        
        return dp[i][j] = solve(grid, r, c, i+1, j, dp) + solve(grid, r, c, i, j+1, dp);
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& grid) 
    {
        int r = grid.size();
        int c = grid[0].size();
        if(!r) return 0;
        vector<vector<int>> dp(r, vector<int>(c, -1));
        int ans = solve(grid, r, c, 0, 0, dp);
        return ans;
    }
};