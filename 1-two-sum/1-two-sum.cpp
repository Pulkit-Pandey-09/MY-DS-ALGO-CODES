class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        int n = nums.size();
        if(!n) return {};
        unordered_map<int, int> up;
        for(int i = 0; i < n; i++)
        {
            int reqNum = target - nums[i];
            if(up.find(reqNum) != up.end())
            {
                return {i, up[reqNum]};
            }
            up[nums[i]] = i;
        }
        return {};
    }
};