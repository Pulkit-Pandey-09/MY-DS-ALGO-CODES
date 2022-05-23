class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        if(s.size() != t.size()) return false;
        vector<int> counter(300, 0);
        for(int i = 0; i < s.size(); i++)
        {
            counter[s[i]]++;
        }
        for(int i = 0; i < t.size(); i++)
        {
            counter[t[i]]--;
            if(counter[t[i]] < 0) return false;
        }
        return true;
    }
};