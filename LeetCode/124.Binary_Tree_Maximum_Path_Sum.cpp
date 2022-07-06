class Solution {
public:
    int maxDiameter_Optimized(TreeNode* root,int &ans) {
        /*
            Time complexity is O(2^n)
            Thi is similar to maxDiameter...There we counted nodes, here we will count sum of nodes value.
        */
        if(root == NULL)
            return 0;
        int leftMax = maxDiameter_Optimized(root->left,ans);
        int rightMax = maxDiameter_Optimized(root->right,ans);
        ans = max(ans, (leftMax < 0 ? 0 : leftMax) + (rightMax < 0 ? 0 : rightMax) + root->val);
    return root->val + (max(leftMax,rightMax)< 0 ? 0 : max(leftMax,rightMax));
    }
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        maxDiameter_Optimized(root,ans);
        return ans;    
    }
};