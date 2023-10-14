/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node)return NULL;
        
        queue<Node*> q;
        q.push(node);
        unordered_map<int,Node*> nodeList;
        nodeList[node->val] = new Node(node->val);
        
        while(!q.empty()){
            Node* cur = q.front(); q.pop();

            vector<Node*> nbr = cur->neighbors;
            int val = cur->val;
            
            for(auto it: nbr){
                if(nodeList.find(it->val)==nodeList.end()){
                    nodeList[it->val] = new Node(it->val);
                    q.push(it);
                }
                
                nodeList[val]->neighbors.push_back(nodeList[it->val]);
            }
        }
        
        return nodeList[1];
    }
};