Link : https://leetcode.com/problems/insert-into-a-binary-search-tree/

Approach : Try to figure out where the given value could have been in the tree.
  Go to the root node compare root with the given val: 1) if(root->val<=key)Go to right. repeat the process until you insert the key to its position
                                                       2) if(root->val>key)Go to left. repeat the process .
                                                         
           -------------------------------------Code----------------------------
                                                         
                                                         
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL)return new TreeNode(val);
        TreeNode* curr=root;
       
        while(root){
            if(curr->val<=val){
                if(curr->right!=NULL)curr=curr->right;
                else{
                    curr->right=new TreeNode(val);
                    break;
                }
            }else{
                  if(curr->left!=NULL)curr=curr->left;
                else{
                    curr->left=new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
  
