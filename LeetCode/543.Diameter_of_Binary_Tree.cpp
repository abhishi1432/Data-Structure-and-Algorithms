class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        int leftMax = 1 + maxDepth(root->left);
        int rightMax = 1 + maxDepth(root->right);
        return max(leftMax,rightMax);
    }
    int ans = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return 0;
        int leftMax = maxDepth(root->left);
        int rightMax = maxDepth(root->right);
        ans = max(ans, leftMax + rightMax );
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        return ans; 
        }
};