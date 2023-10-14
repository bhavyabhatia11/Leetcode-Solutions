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
        Node* ans = new Node(0);
        Node* cur = ans;
        Node* og = head;
        unordered_map<Node*,Node*> mp;

        while(og){
            cur->next = new Node(og->val);
            cur->next->random = og->random;
            mp[og] = cur->next;
            og = og->next;
            cur = cur->next;
        }

        cur = ans->next;
        while(cur){
            cur->random = mp[cur->random];
            cur = cur->next;
        }

        return ans->next;
    }
};