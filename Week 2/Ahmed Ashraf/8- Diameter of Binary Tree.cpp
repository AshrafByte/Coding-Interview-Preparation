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
    int diameterOfBinaryTree(TreeNode *root)
    {
        int maxi = 0;
        getDepth(root, maxi);
        return maxi;
    }

private:
    int getDepth(TreeNode *root, int &maxi)
    {
        if (!root)
            return 0;
        int left = getDepth(root->left, maxi);
        int right = getDepth(root->right, maxi);
        maxi = max(maxi, left + right);
        return 1 + max(left, right);
    }
};
