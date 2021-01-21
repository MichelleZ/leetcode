// Source: https://leetcode.com/problems/copy-list-with-random-pointer/
// Author: Miao Zhang
// Date:   2021-01-21

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
        if (!head) return nullptr;
        unordered_map<Node*, Node*> dicts;
        Node* dummy = new Node(0);
        Node* newhead = dummy;
        Node* tmp = head;
        
        while (tmp) {
            Node* node = new Node(tmp->val, nullptr, nullptr);
            dicts[tmp] = node;
            newhead->next = node;
            tmp = tmp->next;
            newhead = newhead->next;
        }
        tmp = head;
        while (tmp) {
            if (tmp->random) {
                dicts[tmp]->random = dicts[tmp->random];
            }
            tmp = tmp->next;
        }
        return dummy->next;
    }
};
