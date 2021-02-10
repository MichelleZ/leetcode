// Source: https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/
// Author: Miao Zhang
// Date:   2021-02-10

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return nullptr;
        stack<Node*> st;
        Node* p = head;
        while (p) {
            if (p->child) {
                if (p->next) {
                    st.push(p->next);
                }
                p->child->prev = p;
                p->next = p->child;
                p->child = nullptr;
            }
            if (!p->next && !st.empty()) {
                Node* last_next = st.top();
                st.pop();
                p->next = last_next;
                last_next->prev = p;
            }
            p = p->next;
        }
        return head;
    }
};
