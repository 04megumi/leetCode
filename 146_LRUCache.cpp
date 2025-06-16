class LRUCache {
private:
    struct Node {
        int key, val;
        Node* next;
        Node* pre;
        Node(int k, int v) : key(k), val(v), next(nullptr), pre(nullptr) {}
    };

    int capacity;
    unordered_map<int, Node*> hash;
    Node* head;
    Node* tail; 
    void insertToHead(Node* node) {
        node->next = head->next;
        node->pre = head;
        head->next->pre = node;
        head->next = node;
    }
    void remove(Node* node) {
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }
    void moveToHead(Node* node) {
        remove(node);
        insertToHead(node);
    }

public:
    LRUCache(int capacity) : capacity(capacity) {
        head = new Node(-1, -1); 
        tail = new Node(-1, -1);
        head->next = tail;
        tail->pre = head;
    }
    int get(int key) {
        if (hash.find(key) == hash.end()) return -1;
        Node* node = hash[key];
        moveToHead(node);
        return node->val;
    }
    void put(int key, int value) {
        if (hash.find(key) != hash.end()) {
            Node* node = hash[key];
            node->val = value;
            moveToHead(node);
        } else {
            if (hash.size() >= capacity) {
                Node* del = tail->pre;
                remove(del);
                hash.erase(del->key);
                delete del;
            }
            Node* node = new Node(key, value);
            insertToHead(node);
            hash[key] = node;
        }
    }

};