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
private:
    unordered_map<Node*,Node*> hash;
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        Node* temp = nullptr;
        if(hash.find(node)==hash.end()) {
            temp = new Node(node->val);
            hash[node] = temp;
        }
        temp = hash[node];
        for(auto& cur : node->neighbors) {
            if(hash.find(cur)==hash.end()) cloneGraph(cur);  
            temp->neighbors.push_back(hash[cur]);
        }
        return temp;
    }
};