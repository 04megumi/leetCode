class WordDictionary {
struct Node {
    char val;
    bool isEnd;
    vector<Node*> nexts;
    Node(): val('.'), isEnd(false) {};
    Node(char v): val(v), isEnd(false) {};
};
Node* root;
public:
    WordDictionary() {
        root = new Node();
        root->nexts.resize(26,nullptr);
    }
    
    void addWord(string word) {
        Node* cur = root;
        for(auto& w : word) {
            if(cur->nexts[w-'a']==nullptr) {
                Node* newNode = new Node(w);
                newNode->nexts.resize(26,nullptr);
                cur->nexts[w-'a'] = newNode;
            }
            cur = cur->nexts[w-'a'];
        }
        cur->isEnd = true;
    }
    
    bool search(string word) {
        return search(word,0,root);
    }

    bool search(string word, int index, Node* cur) {
        if(index==word.size()) 
            return cur->isEnd;
        for(int i=0;i<26;i++) {
            if(cur->nexts[i]!=nullptr&&(word[index]=='.'||('a'+i)==word[index])) {
                if(search(word,index+1,cur->nexts[i])) 
                    return true;
            }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */