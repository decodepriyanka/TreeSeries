Problem link: https://leetcode.com/problems/same-tree/

Input: p = [1,2,3], q = [1,2,3]
Output: true
  
  You can traverse the tree with any of the method : inorder,preorder or postorder.
   I am doing preorder traversal.
    -------------CODE----------------
    
    class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL || q==NULL)
            return (p==q);
   return (p->val==q->val) && isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
};
