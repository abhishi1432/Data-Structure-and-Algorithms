vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL)
            return ans;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            TreeNode* temp = s.top();
            s.pop();
            ans.push_back(temp->val);
            if(temp->right!=NULL)
                s.push(temp->right);
            if(temp->left!=NULL)
                s.push(temp->left);
        }
        return ans;
    }