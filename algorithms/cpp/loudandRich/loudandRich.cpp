// Source: https://leetcode.com/problems/loud-and-rich/
// Author: Miao Zhang
// Date:   2021-03-18

class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>> graph(n);
        for (auto& r: richer) {
            graph[r[1]].push_back(r[0]);
        }
        vector<int> res(n, -1);
        for (int i = 0; i < n; i++) {
            dfs(i, res, graph, quiet);
        }
        return res;
    }

private:
    void dfs(int i, vector<int>& res, vector<vector<int>>& graph, vector<int>& quiet) {
        if (res[i] != -1) return;
        res[i] = i;
        for (int j: graph[i]) {
            dfs(j, res, graph, quiet);
            if (quiet[res[j]] < quiet[res[i]]) {
                res[i] = res[j];
            }
        }
    }
};
