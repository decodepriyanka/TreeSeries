Question link : https://practice.geeksforgeeks.org/problems/binary-tree-to-bst/1/?page=1&category[]=Binary%20Search%20Tree&sortBy=submissions#

Approach : inorder traverse the binary tree store the result in a vector v ; 
sort the vector : the sorted BT is always inorder traversal of BST;

class Solution{
  public:
   
    void inorder_BT(Node * root , vector<int>&v){
        if(!root)return;
        inorder_BT(root->left,v);
        v.push_back(root->data);
        inorder_BT(root->right,v);
    }
    void inorder_bst(Node* root,vector<int>v, int &i){
        if(!root)return;
        inorder_bst(root->left,v,i);
        root->data = v[i];
        i++;
        inorder_bst(root->right,v,i);
    }
    Node *binaryTreeToBST (Node *root)
    {
        vector<int>v;
        inorder_BT(root,v);
        sort(v.begin(),v.end());
        int i =0;
        inorder_bst(root,v,i);
        return root;
        //Your code goes here
    }
};
