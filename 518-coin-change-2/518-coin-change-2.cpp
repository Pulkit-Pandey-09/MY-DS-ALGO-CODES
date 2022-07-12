class Solution {
public:
    
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