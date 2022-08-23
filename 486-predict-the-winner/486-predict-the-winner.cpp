class Solution {
public:
    #define ll long long
    ll optimalGame(vector<int>& nums, ll i, ll j)
    {
        if(i > j){
            return 0;
        }

        // Consider both the possibilities. You can pick either the first or the last coin.
        // Since the opponent plays optimally , we would get the minimum of the remaining coins for each choice.
        ll pickFirst = nums[i] + min( optimalGame(nums,i+2,j) , optimalGame(nums,i+1,j-1) ) ;
        ll pickLast = nums[j] + min( optimalGame(nums,i,j-2) , optimalGame(nums,i+1,j-1) ) ;

        // Pick the max of two as your final result
        ll ans = max(pickFirst,pickLast);
        return ans;
    }
    
    bool PredictTheWinner(vector<int>& nums) 
    {
        if(nums.size() <= 1) return true;
        ll total = 0;
        for(auto x : nums) total += x;
        ll ans = optimalGame(nums,0,nums.size()-1);
        return (ans >= (total-ans));
    }
};