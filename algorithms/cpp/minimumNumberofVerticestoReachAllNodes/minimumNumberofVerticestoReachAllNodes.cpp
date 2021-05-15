// Source: https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/
// Author: Miao Zhang
// Date:   2021-05-15

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> in(n);
        for (const auto& e : edges) ++in[e[1]];
        vector<int> res;
        for (int i = 0; i < n; ++i)
            if (in[i] == 0) res.push_back(i);
        return res;
    }
};
