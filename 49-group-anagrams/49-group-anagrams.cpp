class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        unordered_map<string, vector<string>> up;
        vector<vector<string>> ans;
        for(int i = 0; i < strs.size(); i++)
        {
            string sortStr = strs[i];
            sort(sortStr.begin(), sortStr.end());
            if(up.count(sortStr))
            {
                up[sortStr].push_back(strs[i]);
            }
            else
            {
                up[sortStr].push_back(strs[i]);
            }
        }
        for(auto x : up)
        {
            ans.push_back(x.second);
        }
        return ans;
    }
};