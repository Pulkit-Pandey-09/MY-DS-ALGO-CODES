class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int maxProduct = nums[0];
        int minProduct = nums[0];
        int temp = nums[0];
        int ans = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            temp = max(maxProduct * nums[i], max(minProduct * nums[i], nums[i]));
            minProduct = min(minProduct * nums[i], min(maxProduct * nums[i], nums[i]));
            maxProduct = temp;
            ans = max(ans, maxProduct);
        }
        return ans;
    }
};