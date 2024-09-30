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
    int flg = 0;

    bool isBalanced(TreeNode *root) {

        dp(root);
        return flg == 0;

    }

    int dp(TreeNode *root) {
        if (root == NULL) return 0;
        int left = dp(root->left);
        int right = dp(root->right);

        if (abs(right - left) > 1) {
            flg = 1;

        }
        return max(left, right) + 1;

    }

};