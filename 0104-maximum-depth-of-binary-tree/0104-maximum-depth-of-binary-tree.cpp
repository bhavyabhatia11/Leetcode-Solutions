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
    void dfs(TreeNode* root, int curDep, int& ans){
        
        if(root == NULL){
            return;
        }
        
        ans = max(ans,curDep);
        
        if(root->left){
            dfs(root->left,curDep+1,ans);
        }
        
        if(root->right){
            dfs(root->right,curDep+1,ans);
        }
        
        return;
        
    }
    
    int maxDepth(TreeNode* root) {
        
        if(root == NULL) return 0;
        
        int ans = 1;
        dfs(root,1,ans);
        
        
        return ans;
        
    }
};