vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int> level;
            for(int i=0;i<n;i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left!=NULL)
                    q.push(temp->left);
                if(temp->right!=NULL)
                    q.push(temp->right);
                level.push_back(temp->val);
            }
            ans.push_back(level);
        }
        int n=ans.size();
        for(int i=0;i<n/2;i++){
            vector<int>temp= ans[i];
            ans[i] = ans[n-1-i];
            ans[n-1-i] = temp;
        }
        return ans;
    }