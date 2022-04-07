Link : https://leetcode.com/problems/symmetric-tree/
Input: root = [1,2,2,3,4,4,3]
Output: true
  
  Property of Mirror - The left is looking at the right and the right is looking at left.
  
  
  -------------------code---------------------
  
    bool isSymmetric(TreeNode* root) {
        return root==NULL || isSymmetricboth(root->left,root->right);
        
    }
    bool isSymmetricboth(TreeNode* left,TreeNode* right){
        if(left==NULL || right==NULL)return left==right;
        if(left->val!=right->val)return false;
        return isSymmetricboth(left->left,right->right)&& isSymmetricboth(left->right,right->left);
    }
