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
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        ListNode* ans = new ListNode(); 
        ListNode* res = ans;
       
        
        stack<int> s;
        
        
        while(head){
            s.push(head->val);
            head = head->next;
        }
        
        
        while(!s.empty()){
            ans->next = new ListNode(s.top());
            ans = ans->next;
            s.pop();
        }
        
        
        return res->next;
        
    }
};