class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        int leftMin = 1+minDepth(root->left);
        int rightMin = 1+minDepth(root->right);
        if(leftMin == 1)
            return rightMin;
        if(rightMin == 1)
            return leftMin;
        return min(leftMin , rightMin);
    }
};