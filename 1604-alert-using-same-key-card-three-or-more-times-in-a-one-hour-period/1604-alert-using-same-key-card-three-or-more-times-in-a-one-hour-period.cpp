class Solution {
public:
    int toTime(string &s)   // into minutes
    {
        int h = (s[0] - '0') * 10 + (s[1] - '0');
        int m = (s[3] - '0') * 10 + (s[4] - '0');

        return h * 60 + m;
    }
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) 
    {
        int n = keyName.size();
        map<string, vector<int>> myMap;
        vector<string> res;

        // hashmap, collect the keyTime for each keyName.
        for (int i = 0; i < n; i++)
        {
            myMap[keyName[i]].push_back(toTime(keyTime[i]));
        }

        for (auto h : myMap)
        {
            if (h.second.size() < 3) continue;
            sort(begin(h.second), end(h.second));

            // sliding window
            int start = 0;
            int end = 0;
            while(end < h.second.size())
            {
                while(h.second[end] - h.second[start] > 60)  // contract (next hour starts)
                {
                    start++;
                }
                if(end - start + 1 == 3)                   // key card was used 3 times in same hour
                {
                    res.push_back(h.first);
                    break;
                }
                end++;                                  // same hour
            }
        }

        return res;
    }
};