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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        if(!root) return {};
        vector<vector<int>> result;
        queue<TreeNode*> q;
        q.push(root);
        bool parity = false;  // T - right to left ; F - left to right
        while(!q.empty())
        {
            int s = q.size();
            vector<int> temp(s);
            for(int i = 0; i < s; i++)
            {
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                
                int index = parity ? s-i-1 : i; 
                temp[index] = curr->val;
            }
            result.push_back(temp);
            temp.clear();
            parity = !parity;
        }
        return  result;
    }
};