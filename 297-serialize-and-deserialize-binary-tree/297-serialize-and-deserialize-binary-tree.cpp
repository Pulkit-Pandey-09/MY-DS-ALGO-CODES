/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        string s = "";
        if(!root) return s;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* curr = q.front();
            q.pop();
            if(!curr) s.append("#,");
            else s.append(to_string(curr->val)+',');
            if(curr)
            {
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        if(!data.size()) return NULL;
        queue<TreeNode*> q;
        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        q.push(root);
        while(!q.empty())
        {
            TreeNode* curr = q.front();
            q.pop();
            
            getline(s, str, ',');
            if(str == "#")
            {
                curr->left = NULL;
            }
            else
            {
                TreeNode* lft = new TreeNode(stoi(str));
                curr->left = lft;
                q.push(lft);
            }
            
            getline(s, str, ',');
            if(str == "#")
            {
                curr->right = NULL;
            }
            else
            {
                TreeNode* rgt = new TreeNode(stoi(str));
                curr->right = rgt;
                q.push(rgt);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));