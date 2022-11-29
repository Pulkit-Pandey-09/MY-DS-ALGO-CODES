class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) 
    {
        vector<int> prefixSum(nums.size());
        prefixSum[0] = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }
        double res = prefixSum[k-1]*1.0/k;
        for(int i = k; i < prefixSum.size(); i++)
        {
            double sum = (prefixSum[i]-prefixSum[i-k])*1.0/k;
            res = max(res, sum);
        }
        return res;
    }
};


