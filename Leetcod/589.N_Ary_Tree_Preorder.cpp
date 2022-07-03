vector<int> preorder(Node* root) {
        vector<int> ans;
        if(root==NULL)
            return ans;
        stack<Node*> s;
        s.push(root);
        while(!s.empty()){
            Node* temp = s.top();
            s.pop();
            ans.push_back(temp->val);
            for(auto it= (temp->children).rbegin();it!=(temp->children).rend();++it)
                if(*it!=NULL)
                    s.push(*it);
        }
        return ans;
    }