class Solution {
public:
    int minOperations(vector<string>& logs) 
    {
        int steps = 0;
        for(auto cmd : logs)
        {
            if(cmd == "../")
            {
                steps = max(0, steps-1);
            }
            else if(cmd == "./")
            {
                continue;
            }
            else
            {
                steps++;
            }
        }
        return steps;
    }
};