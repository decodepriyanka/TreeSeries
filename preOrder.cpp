// ---Preorder   root->left->right

/* We can solve this using two methods:
    1)Recursion
    2)Iteratively
    */


//=================RECURSIVE============================

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> v;
    vector<int> preorderTraversal(TreeNode* root) {
         if(root == NULL) return v;
        
        v.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        
        return v;
    }
   
};

//=============ITERATIVE SOLUTION================

// Create a stack, take the root and push it into the stack , if there exist its left push its left and then its left and so on. When you see there is NULL there is not need to move further
// Take out the top element of the stack and print it. After that go the right and follow the same process.

// ...........................CODE................

 vector<int> v;
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        while(root||!s.empty()){
            if(root!=NULL){
                s.push(root);
                root=root->left;
            }
            else{
                root=s.top();
                s.pop();
                v.push_back(root->val);
                root=root->right;
            }
          }
         return v;
    }
        
