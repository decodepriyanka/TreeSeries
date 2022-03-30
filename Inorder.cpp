// Inorder traversal - left->root->right

/* We can solve this using two methods:
    1)Recursion
    2)Iteratively
    */

 // 1) Recursion

void inorder(Node* root,vector<int> &v)
    {
        if(root == NULL)
            return;
        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
    }
  public:

    vector<int> inOrder(Node* root) {
      
        vector<int> res;
        inorder(root,res);
        return res;
        
    }

// 2. Iterative 

class Solution {

public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st; 
        TreeNode* node = root;
        vector<int> inorder; 
        while(true) {
            if(node != NULL) {
                st.push(node); 
                node = node->left; 
            }
            else {
    
                if(st.empty() == true) break; 
                node = st.top(); 
                st.pop(); 
                inorder.push_back(node->val); 
                node = node->right; 
            }  
        }
        return inorder; 
    }
};
