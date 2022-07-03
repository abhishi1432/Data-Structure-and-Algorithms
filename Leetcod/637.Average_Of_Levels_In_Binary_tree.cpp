vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if(root==NULL)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            double level=0;
            for(int i=0;i<n;i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left!=NULL)
                    q.push(temp->left);
                if(temp->right!=NULL)
                    q.push(temp->right);
                level+=temp->val;
            }
            
            ans.push_back(level/((double)(n)));
        }
        return ans;
    }