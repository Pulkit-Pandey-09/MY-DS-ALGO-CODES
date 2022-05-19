class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) 
    {
        int n = nums.size();
        stack<int> s;
        vector<int> v(n, -1);
        s.push(nums[n-1]);
        for(int i = 2*n-2; i >= 0; i--)
        {
            while(!s.empty() && nums[i%n] >= s.top())
            {
                s.pop();
            }
            if(!s.empty()) v[i%n] = s.top();
            s.push(nums[i%n]);
        }
        return v;
    }
};