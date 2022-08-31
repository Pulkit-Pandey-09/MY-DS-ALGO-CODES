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
    
    TreeNode* solve(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>& idx)
    {
        if(preStart > preEnd || inStart > inEnd) return NULL;
        
        int rootVal = preorder[preStart];
        int i = idx[rootVal];
        int numsLeft = i - inStart;
            
        TreeNode* root = new TreeNode(rootVal);
        root->left = solve(preorder, preStart+1, preStart+numsLeft, inorder, inStart, i-1, idx);
        root->right = solve(preorder, preStart+numsLeft+1, preEnd, inorder, i+1, inEnd, idx);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        unordered_map<int, int> idx;
        for(int i = 0; i < inorder.size(); i++)
        {
            idx[inorder[i]] = i;
        }
        return solve(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, idx);
    }
};