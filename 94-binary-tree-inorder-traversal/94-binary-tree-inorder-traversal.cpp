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
    vector<int> inorderTraversal(TreeNode* root) 
    {
        TreeNode* curr = root;
        TreeNode* prev = root;
        vector<int> inorder;
        while(curr)
        {
            if(!curr->left) // 1.there is no left tree  2.curr node is root node
            {
                inorder.push_back(curr->val);
                curr = curr->right;
            }
            else // I want to come back to my root node in O(1) time. So ill add threaded edge from last-most right node to curr node .
            {
                prev = curr->left;
                while(prev->right && prev->right != curr)
                {
                    prev = prev->right;
                }
                
                if(!prev->right)
                {
                    prev->right = curr;
                    curr = curr->left;
                }
                if(prev->right == curr) // threaded edge already added before - means this left tree has already been processed.
                {
                    prev->right = NULL;
                    inorder.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return inorder;
    }
};