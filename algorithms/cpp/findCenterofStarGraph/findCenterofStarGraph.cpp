// Source: https://leetcode.com/problems/find-center-of-star-graph/
// Author: Miao Zhang
// Date:   2021-06-08

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> degrees;
        for (auto& e: edges) {
            if (++degrees[e[0]] > 1) return e[0];
            if (++degrees[e[1]] > 1) return e[1];
        }
        return -1;
    }
};
