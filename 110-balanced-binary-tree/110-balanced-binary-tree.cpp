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
    
    pair<int, bool> solve(TreeNode* root)
    {
        if(!root) return {0,true};
        pair<int, bool> l = solve(root->left);
        pair<int, bool> r = solve(root->right);
        int h = max(l.first,r.first)+1;
        bool ans = false;
        if(abs(l.first-r.first) <= 1 && l.second && r.second) ans = true;
        return {h, ans};
    }
    bool isBalanced(TreeNode* root) 
    {
        pair<int, bool> ans = solve(root);
        return ans.second;
    }
};