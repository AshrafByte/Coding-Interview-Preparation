//
// Created by Ahmed hesen on 10/13/2024.
//

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
    int diameter =0;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        maxdepth(root);
        return  diameter;
    }
    int maxdepth(TreeNode* root){
        if(root == NULL) return 0;
        int rdepth = maxdepth(root->right);
        int ldepth = maxdepth(root->left);
        diameter = max(diameter, rdepth + ldepth);
        return 1 + max(rdepth, ldepth);
    }
};