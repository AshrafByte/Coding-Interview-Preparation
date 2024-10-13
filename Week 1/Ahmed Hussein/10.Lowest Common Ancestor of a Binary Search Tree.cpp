//
// Created by Ahmed hesen on 10/11/2024.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    bool foundp=0, foundq=0;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(root == NULL) return root;
        if(q->val < root->val && p->val < root->val) return lowestCommonAncestor(root->left,  p, q);
        if(q->val > root->val && p->val > root->val) return lowestCommonAncestor(root->right, p, q);
        return root;

    }
};