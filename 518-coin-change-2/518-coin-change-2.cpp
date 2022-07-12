class Solution1 {
public:
    // recursion + memo ( top down approach)
    int solve(vector<int>& coins, int n, int amt, int i, vector<vector<int>>& dp)
    {
        // base case
        if(amt == 0) return 1;
        if(i >= n) return 0;
        if(dp[i][amt] != -1) return dp[i][amt];
        int incl = 0;
        int exl = 0;
        if(amt >= coins[i])
        {
            incl = solve(coins, n, amt-coins[i], i, dp);
        }
        exl = solve(coins, n, amt, i+1, dp);
        return dp[i][amt] = incl + exl;
    }
    
    int change(int amount, vector<int>& coins) 
    {
        int n = coins.size();
        if(!n) return 0;
        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
        int ans = solve(coins, n, amount, 0, dp);
        return ans;
    }
};
class Solution {
public:
    // bottom -up approach
    int dp[301][5001];
    
    int tabulation(int w, vector<int>& wt, int n)
    {
        for(int i = 0; i <= n; i++)
        {
            for(int j = 0; j <= w; j++)
            {
                if(i == 0 || j == 0)
                {
                    dp[i][j] = (j == 0 ? 1 : 0);
                }
            }
        }
        dp[0][0] = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= w; j++)
            {
                int incl = 0;
                int exl = 0;
                if(wt[i-1] <= j)
                {
                    incl = dp[i][j-wt[i-1]];
                }
                exl = dp[i-1][j];
                dp[i][j] = incl + exl;
            }
        }
        
        return dp[n][w];
    }
    
    int change(int amount, vector<int>& coins) 
    {
        memset(dp, -1, sizeof(dp));
        return tabulation(amount, coins, coins.size());    
    }
};