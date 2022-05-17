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
    
   vector<vector<int>> levelOrderTraversal(TreeNode* root)
    {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int s = q.size();
            vector<int> temp;
            while(s--)
            {
                TreeNode* currNode = q.front();
                q.pop();
                if(currNode->left) q.push(currNode->left);
                if(currNode->right) q.push(currNode->right);
                temp.push_back(currNode->val);
            }
            ans.push_back(temp);
        }
        return ans;
    }
    
    vector<int> largestValues(TreeNode* root) 
    {
        /* levelOrderTraversal array
            1 fill levelOrderTraversal array/vector
                1.a height of tree. --- O(n2)
                1.b using queue.    --- O(n) 
            2. traverse levelOrderTraversal array/vector to fill my answer vector
        */
        vector<vector<int>> levelOrder = levelOrderTraversal(root);
        vector<int> ans;
        for(int i = 0; i < levelOrder.size(); i++)
        {
            int temp = INT_MIN;
            for(int j = 0; j < levelOrder[i].size(); j++)
            {
                temp = max(temp, levelOrder[i][j]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
