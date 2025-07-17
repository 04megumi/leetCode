class Trie {
private:
    struct Node {
        char val;
        unordered_map<char,Node*> nexts;

        Node() : val(' ') {}
        Node(char v) : val(v) {}
    };
    Node* root = nullptr;
public:
    Trie() {
        this->root = new Node();
    }
    
    void insert(string word) {
        Node* cur = root;
        for(auto& w : word) {
            if(cur->nexts.find(w)==cur->nexts.end()) {
                Node* newNode = new Node(w);
                cur->nexts[w] = newNode;
            }
            cur = cur->nexts[w];
        }
        cur->nexts['.'] = nullptr;
    }
    
    bool search(string word) {
        Node* cur = root;
        for(auto& w : word) {
            if(cur->nexts.find(w)==cur->nexts.end()) {
                return false;
            }
            cur = cur->nexts[w];
        }
        return cur->nexts.find('.')!=cur->nexts.end();
    }
    
    bool startsWith(string prefix) {
        Node* cur = root;
        for(auto& w : prefix) {
            if(cur->nexts.find(w)==cur->nexts.end()) {
                return false;
            }
            cur = cur->nexts[w];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */