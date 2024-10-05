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
    bool isValidBST(TreeNode *root) {

        function<bool(TreeNode * , long, long)> go = [&](TreeNode *node, long minimum, long maximum) -> bool {
            if (node == NULL) return true;

            if (!(node->val > minimum && node->val < maximum)) return false;
            return go(node->left, minimum, node->val) && go(node->right, node->val, maximum);
        };
        return go(root, LONG_MIN, LONG_MAX);
    }
};