class Solution {
public:
    int triangleNumber(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        int l, r, res = 0;
        for(int i = nums.size()-1; i >= 2; i--)
        {
            r = i-1;
            l = 0;
            while(l < r)
            {
                if(nums[l] + nums[r] > nums[i])
                {
                    res += (r-l);
                    r--;
                }
                else
                {
                    l++;
                }
            }
        }
        return res;
    }
};