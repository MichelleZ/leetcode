// Source: https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/
// Author: Miao Zhang
// Date:   2021-05-13

class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> g(n);
        for (auto& e: edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        vector<int> seen(n);
        vector<int> cnt(26);
        vector<int> res(n);
        function<void(int)> postOrder = [&] (int i) {
            if (seen[i]++) return;
            int before = cnt[labels[i] - 'a'];
            for (int j: g[i]) postOrder(j);
            res[i] = ++cnt[labels[i] - 'a'] - before;
        };
        postOrder(0);
        return res;
    }
};
