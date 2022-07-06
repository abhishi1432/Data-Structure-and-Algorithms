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


int maxDiameter_Optimized(TreeNode* root,int &ans) {
    /*
        Time complexity is O(2^n)
    */
    if(root == NULL)
        return 0;
    int leftMax = maxDiameter_Optimized(root->left,ans);
    int rightMax = maxDiameter_Optimized(root->right,ans);
    ans = max(ans,leftMax+rightMax);
    return 1 + max(leftMax,rightMax);
}