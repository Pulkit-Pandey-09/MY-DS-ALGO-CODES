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
    #define ll long long
    bool solve(TreeNode* root, ll m, ll M)
    {
        if(!root) return true;
        if(root->val > m && root->val < M)
        {
            return solve(root->left, m, root->val) && solve(root->right, root->val, M);
        }
        return false;
    }
    
    bool isValidBST(TreeNode* root) 
    {
        return solve(root, LONG_MIN, LONG_MAX);
    }
};