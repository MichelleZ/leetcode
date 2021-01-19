// Source: https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
// Author: Miao Zhang
// Date:   2021-01-19

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        Node* res = root;
        while (root) {
            Node* tmp = root;
            while (root && root->left) {
                root->left->next = root->right;
                if (root->next) {
                    root->right->next = root->next->left;
                }
                root = root->next;
            }
            root = tmp->left;
        }
        return res;
    }
};

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;
        if (root->left) root->left->next = root->right;
        if (root->right) root->right->next = root->next ? root->next->left : nullptr;
        connect(root->left);
        connect(root->right);
       return root;
    }
};
