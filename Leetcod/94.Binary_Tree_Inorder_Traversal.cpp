vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL)
            return ans;
        stack<TreeNode*> s;
        TreeNode* temp = root;
        while(true){
            if(temp!=NULL){
                s.push(temp);
                temp= temp->left;
            }
            else{
                if(s.empty() == true)
                    break;
                temp = s.top();
                s.pop();
                ans.push_back(temp->val);
                temp= temp->right;
            }
        }
        return ans;
    }