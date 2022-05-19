class Solution {
public:
    
    vector<int> nextGrtElt(vector<int> &nums2)
    {
        stack<int> s;
        vector<int> v(nums2.size(), -1);
        int sz = nums2.size();
        s.push(nums2[sz-1]);
        for(int i = sz-2; i >= 0; i--)
        {
            while(!s.empty() && s.top() <= nums2[i])
            {
                s.pop();
            }
            if(!s.empty()) v[i] = s.top();
            s.push(nums2[i]);
        }
        return v;
    }
    
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_map<int, int> up;
        vector<int> ans(nums1.size(), -1);
        for(int i = 0; i < nums1.size(); i++)  //O(n1*n2) 
        {
            for(int j = 0; j < nums2.size(); j++)
            {
                if(nums1[i] == nums2[j])
                {
                    up[nums2[j]] = j;
                }
            }
        }
        vector<int> v = nextGrtElt(nums2);
        for(int i = 0; i < nums1.size(); i++)
        {
            ans[i] = v[up[nums1[i]]];
        }
        return ans;
    }
};