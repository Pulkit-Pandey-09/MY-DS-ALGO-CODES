class Solution {
public:
    int minMutation(string beginWord, string endWord, vector<string>& bank) 
    {
        set<string> s = {bank.begin(), bank.end()};
        queue<string> q;
        set<string> vis;
        if(s.find(endWord) == s.end()) return -1;
        q.push(beginWord);
        vis.insert(beginWord);
        int level = 0;
        vector<char> mymap = {'A', 'C', 'G', 'T'};
        while(!q.empty())
        {
            int n = q.size();
            while(n--)
            {
                string curr = q.front();
                q.pop();
                for(int i = 0; i < curr.size(); i++)
                {
                    string temp = curr;
                    for(auto c : mymap)
                    {
                        temp[i] = c;
                        if(temp == curr) continue;
                        else if(temp == endWord) return level + 1;
                        else if(s.find(temp) != s.end() && vis.find(temp) == vis.end())
                        {
                            q.push(temp);
                            vis.insert(temp);
                        }
                    }
                }
            }
            level++;
        }
        return -1;
    }
};