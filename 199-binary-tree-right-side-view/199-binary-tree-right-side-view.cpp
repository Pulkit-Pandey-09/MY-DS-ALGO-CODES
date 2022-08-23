/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, int level, int hd, map<int,pair<int,int>> &mp)
    {
        if(!root) return;
    // cout << level << " " << root->val << " " << hd << endl; 
        if(mp.find(level) == mp.end())// || hd > mp[level].second)
        {
            mp[level].first = root->val;
            mp[level].second = hd;
            //cout << level << " " << root->val << " " << hd << endl; 
        }
 
        solve(root->right,level+1,hd+1,mp);
        solve(root->left,level+1,hd-1,mp);
    }
    vector<int> rightSideView(TreeNode* root) 
    {
        map<int,pair<int,int>> mp; //level,(node->val,hd)
        solve(root,0,0,mp);
        vector<int> ans;
        for(auto val : mp)
        {
            ans.push_back(val.second.first);
        }
        return ans;
    }
};