class Solution1 {
public:
    
    int lcs(string texta, string textb, int la, int lb, int i, int j, vector<vector<int>>& dp)
    {
        if(i >= la || j >= lb) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        if(texta[i] == textb[j])
        {
            ans = 1 + lcs(texta, textb, la, lb, i+1, j+1, dp);
        }
        else
        {
            ans = max(lcs(texta, textb, la, lb, i+1, j, dp), lcs(texta, textb, la, lb, i, j+1, dp));
        }
        dp[i][j] = ans;
        return ans;
    }
    
    int longestCommonSubsequence(string texta, string textb) 
    {
        int la = texta.size();
        int lb = textb.size();
        vector<vector<int>> dp(1004, vector<int>(1004, -1));
        int ans = lcs(texta, textb, la, lb, 0, 0, dp);
        return ans;
    }
};

class Solution{
    public:
    int longestCommonSubsequence(string text1, string text2)
    {
        
     int n = text1.length();
     int m = text2.length();
     
     int dp[n+1][m+1];
     // Initialisation
     for(int i=0; i<n+1; i++)    // 1st column
         dp[i][0] = 0;
     for(int j=0; j<m+1; j++)    // 1st row
         dp[0][j] = 0;
     
     // Choice Diagram
     for(int i=1; i<n+1; i++)
         for(int j=1; j<m+1; j++)
         {
             if(text1[i-1] == text2[j-1])
                 dp[i][j] = 1 + dp[i-1][j-1];
             else
                 dp[i][j] = max( dp[i-1][j], dp[i][j-1] );
         }
     
     return dp[n][m];
    }
};