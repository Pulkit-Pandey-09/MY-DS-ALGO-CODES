//solution 1
class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        if(s.size() == 0) return 0;
        int i = 0;
        int j = 0;
        unordered_map<int,int> record;
 
        int ans = INT_MIN;
 
        for(j = 0 ; j < s.size() ; j++)
        {
            record[s[j]]++;
 
            if(record.size() < j-i+1) //contract
            {
                while(record.size() < j-i+1)
                {
                    record[s[i]]--;
                    if(record[s[i]] == 0)
                    {
                        record.erase(s[i]);
                    }
                    i++;
                }
            }
 
            ans = max(ans,j-i+1);
        }
        return ans;
    }
};
 
 
//solution 2
class Solution1 {
public:
 
    int windowProblem(string s)
    {
        int len = s.length();
        if(!len) return 0;
 
        int i = 0;
        int min_window = INT_MIN;
        vector<int> F(256,0);
        for(int j = 0 ; j < len ; j++)
        {
            char ch = s[j];
            F[ch]++;
 
            if(F[ch] > 1) // contraction
            {
                char temp = s[i];
                while(F[ch] > 1)
                {
                    F[temp]--;
                    i++;
                    temp = s[i];
                }
            }
            int min_len = j - i + 1;
            min_window = max(min_window , min_len);
        }
        return min_window;
    }
 
    int lengthOfLongestSubstring(string s) 
    {
        int ans = windowProblem(s);
        return ans;
    }
};