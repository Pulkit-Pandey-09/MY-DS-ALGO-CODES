class Solution {
public:
    vector<vector<int>> offSet = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    
    bool okay(vector<vector<int>>& mat, int r, int c, int i, int j)
    {
        return i >= 0 && i < r && j >= 0 && j < c && mat[i][j] == 1;
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        int r = mat.size();
        int c = mat[0].size();
        if(!r) return {};
        vector<vector<int>> ans(r, vector<int>(c, 0));
        queue<pair<int,int>> q;
        int level = 0;
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                if(!mat[i][j]) 
                {
                    q.push(make_pair(i,j));
                    mat[i][j] = -1;
                }
            }
        }
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                pair<int, int> curr = q.front();
                q.pop();
                if(mat[curr.first][curr.second])
                {
                    ans[curr.first][curr.second] = level;
                }
                for(int i = 0; i < 4; i++)
                {
                    int idx = curr.first + offSet[i][0];
                    int idy = curr.second + offSet[i][1];
                    if(okay(mat, r, c, idx, idy))
                    {
                        q.push(make_pair(idx, idy));
                        mat[idx][idy] = -1;
                    }
                }
            }
            level++;
        }
        return ans;
    }
};