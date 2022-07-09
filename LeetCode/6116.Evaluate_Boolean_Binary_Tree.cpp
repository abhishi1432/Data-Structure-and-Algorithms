class Solution {
public:
    bool postorder(TreeNode* root){
        if(!root)
            return true;
        bool left = postorder(root->left);
        bool right = postorder(root->right);
        if(root->val == 2 || root->val == 3)
            root->val = (root->val) ==2 ? (left | right):(left & right);
        return root->val;
    }
    bool evaluateTree(TreeNode* root) {
        return postorder(root);
    }
};