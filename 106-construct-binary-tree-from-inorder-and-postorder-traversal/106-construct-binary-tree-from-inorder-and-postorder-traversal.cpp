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
    
    TreeNode* solve(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd, unordered_map<int, int>& myMap)
    {
        if(inStart > inEnd || postStart > postEnd) return NULL;
        
        int idx = myMap[postorder[postEnd]];
        int numsLeft = idx - inStart;

        TreeNode* root = new TreeNode(postorder[postEnd]);
        root->left = solve(inorder, inStart, idx-1, postorder, postStart, postStart+numsLeft-1, myMap);
        root->right = solve(inorder, idx+1, inEnd, postorder, postStart+numsLeft, postEnd-1, myMap);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        unordered_map<int, int> myMap;
        for(int i = 0; i < inorder.size(); i++)
        {
            myMap[inorder[i]] = i;
        }
        return solve(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, myMap);
    }
};