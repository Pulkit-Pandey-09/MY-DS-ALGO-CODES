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
    vector<int> largestValues(TreeNode* root) 
    {
        vector<int> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int s = q.size();
            int temp = INT_MIN;
            while(s--)
            {
                TreeNode* currNode = q.front();
                q.pop();
                if(currNode->left) q.push(currNode->left);
                if(currNode->right) q.push(currNode->right);
                temp = max(temp, currNode->val);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
