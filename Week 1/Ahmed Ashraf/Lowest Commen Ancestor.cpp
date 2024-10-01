
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// this solution work on any tree not just binary tree as long nodes are distinct.
class Solution
{
public:
    TreeNode *lca = nullptr;
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        isExisted(root, p, q);
        return lca;
    }
    bool isExisted(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr)
            return false;

        bool left = isExisted(root->left, p, q);
        bool right = isExisted(root->right, p, q);

        if ((left && right) && lca == nullptr)
            lca = root;
            
        if ((left || right) && (root == p || root == q) && lca == nullptr)
            lca = root;

        if (root == p || root == q)
            return true;

        return left || right;
    }
};