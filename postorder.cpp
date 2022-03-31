/* PostOrder ->   left + right + root 
In order to solve this dfs traversal we have two approaches
  1. Recursive
  2. Iterative
  
  ===================Recursive Approach==========================
  */

  void postorder(Node* root,vector<int> &v)
    {
        if(root == NULL)
            return;
        postorder(root->left,v);
        postorder(root->right,v);
        v.push_back(root->data);
       
    }
  public:

    vector<int> postOrder(Node* root) {
      
        vector<int> res;
        postorder(root,res);
        return res;
        
    }

// ================================Iterative============================
  vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;
        stack<TreeNode*> st1;
        TreeNode* current = root;  
        while(current != NULL || !st1.empty()) {
            if(current != NULL){
                st1.push(current);
                current = current->left;
            }else{
                TreeNode* temp = st1.top()->right;
                if (temp == NULL) {
                    temp = st1.top();
                    st1.pop(); 
                   res.push_back(temp->val);
                    while (!st1.empty() && temp == st1.top()->right) {
                        temp = st1.top();
                        st1.pop(); 
                        res.push_back(temp->val);
                    }
                } else {
                    current = temp;
                }
            }
        }
        return res;
    }

