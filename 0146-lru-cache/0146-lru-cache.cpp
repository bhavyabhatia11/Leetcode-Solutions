class Node
{
    public:
    int key;
    int value;
    Node *next;
    Node *prev;
    Node(int k, int v){
        key = k;
        value = v;
        next = NULL;
        prev = NULL;

    }
};


class LRUCache {
public:
    Node* dll = NULL;
    Node* start = NULL;
    Node* end = NULL;
    unordered_map<int, Node*> mp;
    int cap;


    void insertNode(int key, int value) {
        if(start == NULL && end == NULL){
            start = new Node(key, value);
            end = start;
        }
        else{
            end->next = new Node(key, value);
            end->next->prev = end;
            end = end->next;
        }
        
        mp[key] = end;
        return;
    }

    void moveNode(Node* node){

        if(node == end) return;
        if(node == start) {
            end->next = start;
            start->prev = end;
            end = end->next;

            start = start->next;
            start->prev = NULL;
            return;
        }

        Node* temp = node;

        node->prev->next = node->next;
        node->next->prev = node->prev;

        end->next = temp;
        temp->prev = end;

        end = end->next;
        return;
    }

    void evictNode(){
        mp.erase(start->key);
        if(start == end){
            end = NULL;
            start = NULL;
            return;
        }
        start = start->next;
        start->prev = NULL;
        return;
    }

    void printNodes(){
        Node* temp = start;

        cout << cap << ":    " << mp.size() << ":      ";
        while(temp){
            cout << temp->key << "," << temp->value << " ";
            temp=temp->next;
        }
        cout << endl;
    }



    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {

        if(mp.find(key) != mp.end()){
            Node* node = mp[key];
            moveNode(node);
            return end->value;
        }
        else{
            return -1;
        }

    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            // If the key already exists, update the value and move the node to the end
            Node* node = mp[key];
            node->value = value;
            moveNode(node);
        } else {
            // Evict the least recently used node if capacity is full
            while (mp.size() >= cap) {
                evictNode();
            }
            // Insert the new key-value pair
            insertNode(key, value);
        }
        // printNodes();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */