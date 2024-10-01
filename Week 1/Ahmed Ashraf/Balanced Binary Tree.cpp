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
    bool isBalanced(TreeNode *root)
    {
        if (root == nullptr)
            return true;
            
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        
        int diff = abs(leftHeight - rightHeight);
        return (diff <= 1) && isBalanced(root->left) && isBalanced(root->right) ;
    }

    int getHeight(TreeNode *root)
    {
        if (root == nullptr)
            return 0 ;
        return 1 + max(getHeight(root->left),getHeight(root->right));
    }
};

//////////////////////////////////
// better solution in time complexity.
class Solution
{
public:
    unordered_map <TreeNode* , int> treeHeights;
    bool isBalanced(TreeNode *root)
    {   
        if (root == nullptr)
            return true;
            
        if (treeHeights.empty())
            fillMap(root);

        int leftHeight = treeHeights[root->left];
        int rightHeight = treeHeights[root->right];
        
        
        int diff = abs(leftHeight - rightHeight);
        return (diff <= 1) && isBalanced(root->left) && isBalanced(root->right) ;
    }

    void fillMap(TreeNode *root)
    {
        getHeight(root);
    }
    
    int getHeight(TreeNode *root)
    {
        if (root == nullptr)
            return 0 ;
        treeHeights[root] = 1 + max(getHeight(root->left),getHeight(root->right));
        return treeHeights[root];
    }

};