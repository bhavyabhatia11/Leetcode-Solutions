/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;
        Node* cur = new Node(0);
        Node* ans = cur;

        Node* temp = head;
        while(temp){
            cur->next = new Node(temp->val);
            mp[temp] = cur->next;
            temp = temp->next;
            cur = cur->next;
        }

        temp = ans->next;
        while(temp){
            temp->random = mp[head->random];

            temp = temp->next;
            head = head->next;
        }


        return ans->next;
    
    }
};