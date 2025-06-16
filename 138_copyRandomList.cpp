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
private:
    unordered_map<Node*,Node*> hash;
    unordered_map<Node*,vector<Node*>> need;
    Node* pre = nullptr;
public:
    Node* copyRandomList(Node* head) {
        Node* ans = new Node(0); pre = ans;
        while(head) {
            Node* cur = new Node(head->val);
            pre->next = cur; pre = cur;
            if(need.find(head)!=need.end()) for(auto& t : need[head]) t->random = cur;
            hash[head] = cur;
            if(hash.find(head->random)!=hash.end()) {
                cur->random = hash[head->random];
            } else {
                if(head->random) need[head->random].push_back(cur);
            }
            head = head->next;
        }
        return ans->next;
    }
};