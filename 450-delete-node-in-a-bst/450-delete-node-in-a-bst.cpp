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
    
    TreeNode* findChild(TreeNode* root)
    {
        if(!root->right) return root;
        return findChild(root->right);
    }
    
    TreeNode* helper(TreeNode* root, int key)
    {
        if(!root->left) return root->right;
        else if(!root->right) return root->left;
        
        TreeNode* rightChild = root->right;
        TreeNode* lastRightChildInLeftTree = findChild(root->left);
        lastRightChildInLeftTree->right = rightChild;
        return root->left;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if(!root) return NULL;
        if(root->val == key)
        {
            return helper(root, key);
        }
        TreeNode* dummy = root;
        while(root)
        {
            if(key < root->val)
            {
                if(root->left != NULL && root->left->val == key)
                {
                    root->left = helper(root->left, key);
                    break;
                }
                else
                {
                    root = root->left;
                }
            }
            else
            {
                if(root->right != NULL && root->right->val == key)
                {
                    root->right = helper(root->right, key);
                    break;
                }
                else
                {
                    root = root->right;
                }
            }
        }
        return dummy;
    }
};