class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) 
    {
        unordered_map<char, int> map;
        int maxLen = -1;
        for(int i = 0; i < s.size(); i++)
        {
            if(map.count(s[i]) == 1)
            {
                maxLen = max(maxLen, i-map[s[i]]-1);
            }
            else
            {
                map[s[i]] = i;
            }
        }
        return maxLen;
    }
};