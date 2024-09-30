class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return root; 

        queue<TreeNode*> qu;
        qu.push(root); 

        while(!qu.empty()) {
            TreeNode* temp = qu.front();
            qu.pop();

       
            TreeNode* tmpleft = temp->left;
            temp->left = temp->right;
            temp->right = tmpleft;

          
            if(temp->left != NULL) qu.push(temp->left);
            if(temp->right != NULL) qu.push(temp->right);
        }
        return root;
    }
};
