Link : https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

We will be solving this problem by level order and line concept.
ie. Traverse through every node and assign vertical and level to every node.
  
The sole idea of this problem is if you move to left of the tree vertical is decreased by -1 and level increased by +1
If you move to right vertical increased by +1 and level increased by +1;

In this problem, if two nodes are in the same row and column, the order should be from small to large.
  Build the mapping using a queue of pairs of nodes and corresponding coordinates.
  ---------------------------CODE-----------------------
  
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>nodes;
        queue<pair<TreeNode* , pair<int,int>>> todo;
        todo.push({root,{0,0}});
        while(!todo.empty()){
            auto p = todo.front();
            todo.pop();
            TreeNode * node=p.first;
            int x = p.second.first,y = p.second.second;
            nodes[x][y].insert(node->val);
            if(node->left){
                todo.push({node->left,{x-1,y+1}});
            }
            if(node->right){
                todo.push({node->right,{x+1,y+1}});
            }
            
        }
        vector<vector<int>>ans;
        for(auto p :nodes){
            vector<int>col;
            for(auto q:p.second){
                col.insert(col.end(),q.second.begin(),q.second.end());
            }
            ans.push_back(col);
        }
        
        return ans;
    }
};
