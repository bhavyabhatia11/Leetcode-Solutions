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
    ListNode* reverseLL(ListNode* head, ListNode* end){
        if(!head) return head;

        ListNode* cur = head;
        ListNode* prev = NULL;
        ListNode* next = head->next;

        while(cur != end && cur != NULL){
            cur->next = prev;
            prev = cur;
            cur = next;
            if(cur) next = cur->next;
        }

        
        return prev;

    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k<2) return head;
        ListNode* node = head;
        ListNode* start = node;
        int temp = k;
        while(node && temp--){
                node = node->next;
        }
        if(temp<=0){
            ListNode* ans = reverseLL(start, node);
            start->next = reverseKGroup(node,k);
            return ans;
        }
        
        return head;
    }
};