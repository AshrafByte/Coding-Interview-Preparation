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

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {   
        vector<vector<int>> res;
        
        if (!root)
            return res;

        queue<TreeNode *> que;
        que.push(root);

        while (!que.empty())
        {
            int levelSize = que.size();
            vector<int> level;

            while (levelSize--)
            {
                TreeNode *node = que.front();
                que.pop();
                
                level.push_back(node->val);

                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
            }

            res.push_back(level);
        }

        return res;
    }
};
