/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    ListNode* getMid(ListNode* l, ListNode* r){
        if(l==r)return NULL;
        
        ListNode* slow = l;
        ListNode* fast = l;
        
        while(fast != r && fast->next != r){
            fast = fast->next->next;
            slow = slow->next;
        }
        
        return slow;
    }
    
    TreeNode* getBalancedTree(ListNode* l, ListNode* r){
        
        
        ListNode* mid = getMid(l,r);
        if(!mid)return NULL;
        
        TreeNode* node = new TreeNode(mid->val);
        node->left = getBalancedTree(l,mid);
        node->right = getBalancedTree(mid->next,r);
        
        return node;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        return getBalancedTree(head,NULL);
    }
};