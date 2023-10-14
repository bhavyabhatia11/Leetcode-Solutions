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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<pair<TreeNode*,int>> q; 
        int level = 0;
        vector<vector<int>> res;
        
        if(root) q.push({root,0});
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int lev = q.front().second;
            
            if(node->left) q.push({node->left,lev+1});
            if(node->right) q.push({node->right,lev+1});
            
            q.pop();
            
            if(res.size()== lev)res.push_back({});
            res[lev].push_back(node->val);
            
        }
        
        return res;
        
    }
};