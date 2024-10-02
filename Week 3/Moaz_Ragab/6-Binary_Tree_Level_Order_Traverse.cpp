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
    vector<vector<int>> levelOrder(TreeNode* root) {
             if (root == nullptr) {
            return {}; 
        }
        vector ans(2000,vector<int>());
        int last=0;
        function<void(TreeNode*,int)>go=[&](TreeNode* root,int ind)->void
        {
            if(root==NULL) return;
            last=max(ind,last);
            ans[ind].push_back(root->val);
            go(root->left,ind+1);
            go(root->right,ind+1);

        };
        go(root,0);
   ans.resize(last+1);

return ans;
    }
 
};


/********************************* */
/******BFS Solution************* */

#include <vector>
#include <queue>

using namespace std;

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) {
            return ans;
        }

        queue<TreeNode*> q; 
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size(); 
            vector<int> currentLevel; 

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front(); 
                q.pop();
                currentLevel.push_back(node->val); 
                
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            ans.push_back(currentLevel); 
        }

        return ans; 
    }
};
