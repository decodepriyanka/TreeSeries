Problem link: https://leetcode.com/problems/balanced-binary-tree/

Input: root = [3,9,20,null,null,15,7]
Output: true
  

class Solution{
    public:
   
    bool isBalanced(Node *root)
    {
        //  Your Code here
      return height(root)!=-1;
     
    }
     int height(Node *root){
         if(root==NULL)return 0;
          int lh = height(root->left);
          if(lh==-1)return -1;
          int rh=height(root->right);
          if(rh==-1)return -1;
          if(abs(lh-rh)>1)return -1;
          return max(lh,rh)+1;
          
      }
};
