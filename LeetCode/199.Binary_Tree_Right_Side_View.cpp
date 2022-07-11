class Solution {
public:
    vector<int> Usingqueue_helper(TreeNode* root) {
        vector<int> ans;
        if(!root)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i = 0;i<n;i++){
                TreeNode* temp = q.front();
                q.pop();
                if(i==n-1)   //if it is the last i.e rightmost node of a level
                    ans.push_back(temp->val);
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }
        return ans;
    }
    void recursive_helper(TreeNode* root, vector<int> &ans, int i){
        if(root == NULL) 
            return;
        
        if(i == ans.size())
            ans.push_back(root->val);
        recursive_helper(root->right, ans, i+1);
        recursive_helper(root->left, ans, i+1);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        // vector<int> ans;
        // recursive_helper(root, ans, 0);
        // return ans;
        
        return Usingqueue_helper(root);
    }
};