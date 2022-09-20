class Solution {
public:
    int findShortestSubArray(vector<int>& nums) 
    {
        unordered_map<int, int> l;
        unordered_map<int, int> r;
        unordered_map<int, int> c;
        for(int i = 0; i < nums.size(); i++)
        {
            if(l.count(nums[i]) == 0)
            {
                l[nums[i]] = i;
            }
            r[nums[i]] = i;
            c[nums[i]]++;
        }
        int degree = -1;
        for(auto x : c)
        {
            degree = max(degree, x.second);
        }
        int res = INT_MAX;
        for(auto x : c)
        {
            if(x.second == degree)
            {
                res = min(res, r[x.first]-l[x.first]+1);
            }
        }
        return res;
    }
};

/*
    [1,2,2,1,2,1,1,1,1,2,2,2]
*/