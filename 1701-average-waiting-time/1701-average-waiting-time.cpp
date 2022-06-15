class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& cust) 
    {
        int n = cust.size();
        if(!n) return 0;
        double ht, st, et, av = 0;
        for(int i = 0; i < n; i++)
        {
            ht = cust[i][0] > et ? cust[i][0] - et : 0;
            st = et + ht;
            et = st + cust[i][1];
            
            av += (et - cust[i][0]);
        }
        av = double(av/cust.size());
        return av;
    }
};