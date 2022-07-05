class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        /*
        Time complexity is O(n)
        Space Compleixyt is O(logn) -> for recursion stack
    */
        if(!p && !q)
            return true;
        else if((!p && q) || (p && !q))
            return false;
        if(p->val == q->val)   //if roots , left, right of both tree are equal respectively then AND of these will be true
            return true & isSameTree(p->left, q->left) & isSameTree(p->right , q->right);
        else  //if any of the values is not equal, return false, no need to traverse further
            return false;
};