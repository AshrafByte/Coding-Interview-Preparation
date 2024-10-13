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
public:
    int height = 0;
    bool isBalanced(TreeNode* root) {
        return calcheight(root) != -1;
    }

    int calcheight(TreeNode* root){
        if(root == NULL) return 0;
        int rheight = calcheight(root->right);
        if(rheight == -1) return -1;
        int lheight = calcheight(root->left);
        if(lheight == -1) return -1;

        if(abs(rheight - lheight) > 1) return -1;
        else return 1 + max(rheight, lheight);
    }
};