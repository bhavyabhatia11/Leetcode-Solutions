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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return head;
        

        int n = 0;
        ListNode* temp = head;
        while(temp){
            n++;
            temp = temp->next;
        }

        k = k%n;

        temp = head;
        
        ListNode* lastNode = NULL;
        int i = 0;
        while(i < n-k){
            i++;
            lastNode = temp;
            temp = temp->next;
        }

        
        ListNode* firstNode = lastNode->next;
        lastNode->next = NULL;

        
        if (firstNode == NULL) return head;

        temp = firstNode;
        while(temp->next != NULL){
            temp = temp->next;
        }

        temp->next = head;
        
        return firstNode;
    }
};