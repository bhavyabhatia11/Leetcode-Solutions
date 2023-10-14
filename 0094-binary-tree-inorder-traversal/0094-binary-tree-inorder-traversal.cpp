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
    void traverse(TreeNode* root, vector<int>& ans){
        if(!root) return;

        traverse(root->left, ans);
        ans.push_back(root->val);
        traverse(root->right, ans);

        return;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;

        while(root || !s.empty()){
            while(root){
                s.push(root);
                root=root->left;
            }

            root = s.top();
            s.pop();
            ans.push_back(root->val);

            root = root->right;
        }

        return ans;
    }
};