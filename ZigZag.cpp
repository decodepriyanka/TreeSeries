Problem link : https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/submissions/
This problem is same as level order travel ypu just need to maintain a flag variable, which say if are moving from left to right or right to left.
  if left to right -- flag ==0
    right to left --- flag ==1;


class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(root==NULL)return res;
        queue<TreeNode*>q;
        q.push(root);
        bool leftToRight=true;
        while(!q.empty()){
            int n = q.size();
            vector<int>row(n);
            for(int i = 0;i<n;i++){
                TreeNode* node = q.front();
                q.pop();
                 int index = (leftToRight) ? i : n - 1 - i;     
                 row[index]=node->val;
                if(node->left){
                    q.push(node->left);
                }
                if(node->right)
                    q.push(node->right);
            }
             leftToRight=!leftToRight;
        res.push_back(row);
        }
       return res;
    }
};
