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
    int widthOfBinaryTree(TreeNode* root) 
    {
        if(!root) return 0;
        queue<pair<TreeNode*, long long>> q;
        long long first = 0;
        long long last = 0;
        long long width = 0;
        long long currMin = 0;
        long long currId = 0;
        q.push(make_pair(root, 0));
        while(!q.empty())
        {
            int sz = q.size();
            currMin = q.front().second;      // currMin of each level
            for(int i = 0; i < sz; i++)
            {
                TreeNode* currNode = q.front().first;
                currId = q.front().second - currMin;    // to avoid integer overflow
                q.pop();
                if(i == 0) first = currId;
                if(i == sz-1) last = currId;
                if(currNode->left) q.push(make_pair(currNode->left, 2*currId+1));
                if(currNode->right) q.push(make_pair(currNode->right, 2*currId+2));
            }
            width = max(width, last-first+1);
        }
        return width;
    }
};