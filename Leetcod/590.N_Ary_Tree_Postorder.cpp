vector<int> postorder(Node* root) {
        vector<int> ans;
        if(root==NULL)
            return ans;
        stack<Node*> s1,s2;
        s1.push(root);
        while(!s1.empty()){
            root = s1.top();
            s1.pop();
            s2.push(root);
            for(auto i : root->children){
                if(i!=NULL)
                    s1.push(i);   
            }
        }
        while(!s2.empty()){
            ans.push_back(s2.top()->val);
            s2.pop();
        }
        return ans;
    }