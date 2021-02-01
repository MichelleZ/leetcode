// Source: https://leetcode.com/problems/minimum-height-trees/
// Author: Miao Zhang
// Date:   2021-02-01

/*********************************************************************
 * leaves: 1: [0, 2, 3] means 0->1, 2->1, 3->1
 * if leaves[1] == 1 means just one node -> 1; 1 is leaf
*********************************************************************/
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1 && edges.empty()) return {0};
        vector<int> res;
        vector<unordered_set<int>> leaves(n);
        queue<int> q;
        for (auto e: edges) {
            leaves[e[0]].insert(e[1]);
            leaves[e[1]].insert(e[0]);
        }
        for (int i = 0; i < leaves.size(); i++) {
            if (leaves[i].size() == 1) {
                q.push(i);
            }
        }
        while (n > 2) {
            int qsize = q.size();
            n -= qsize;
            for (int i = 0; i < qsize; i++) {
                int u = q.front();
                q.pop();
                for (auto v: leaves[u]) {
                    leaves[v].erase(u);
                    if (leaves[v].size() == 1) {
                        q.push(v);
                    }
                }
            }
        }
        while (!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};
