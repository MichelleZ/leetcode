// Source: https://leetcode.com/problems/logical-or-of-two-binary-grids-represented-as-quad-trees/
// Author: Miao Zhang
// Date:   2021-02-22

/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        if (quadTree1->isLeaf) {
            return quadTree1->val ? quadTree1 : quadTree2;
        }
        if (quadTree2->isLeaf) {
            return quadTree2->val ? quadTree2 : quadTree1;
        }
        Node* tl = intersect(quadTree1->topLeft, quadTree2->topLeft);
        Node *tr = intersect(quadTree1->topRight, quadTree2->topRight);
        Node *bl = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
        Node *br = intersect(quadTree1->bottomRight, quadTree2->bottomRight);
        if (tl->val == tr->val && tl->val == bl->val && tl->val == br->val && tl->isLeaf && tr->isLeaf && bl->isLeaf && br->isLeaf) {
            return new Node(tl->val, true, NULL, NULL, NULL, NULL);
        } else {
            return new Node(false, false, tl, tr, bl, br);
        }
    }
};
