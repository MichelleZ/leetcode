// Source: https://leetcode.com/problems/construct-quad-tree/
// Author: Miao Zhang
// Date:   2021-02-10

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
    Node* construct(vector<vector<int>>& grid) {
        return cons(grid, 0, 0, grid.size());
    }

private:
    Node* cons(vector<vector<int>>& grid, int i, int j, int n) {
        if (n == 0) return nullptr;
        if (n == 1) return new Node(grid[i][j], true, nullptr, nullptr, nullptr, nullptr);
        auto topleft = cons(grid, i, j, n / 2);
        auto topright = cons(grid, i, j + n / 2, n / 2);
        auto bottomleft = cons(grid, i + n / 2, j, n / 2);
        auto bottomright = cons(grid, i + n / 2, j + n / 2, n / 2);

        if (topleft->isLeaf && topright->isLeaf && bottomleft->isLeaf && bottomright->isLeaf && topleft->val == topright->val && topleft->val == bottomleft->val && topleft->val == bottomright->val) {
            auto root = new Node(topleft->val, true, nullptr, nullptr, nullptr, nullptr);
            delete topleft;
            delete topright;
            delete bottomleft;
            delete bottomright;
            return root;
        }
        return new Node(true, false, topleft, topright, bottomleft, bottomright);
    }
};
