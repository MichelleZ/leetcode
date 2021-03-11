// Source: https://leetcode.com/problems/all-paths-from-source-to-target/
// Author: Miao Zhang
// Date:   2021-03-11

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> path{0};
        dfs(graph, path, res);
        return res;
    }

private:
    void dfs(vector<vector<int>>& graph, vector<int>& path, vector<vector<int>>& res) {
        if (path.back() == graph.size() - 1) {
            res.push_back(path);
            return;
        }
        for (int nxt: graph[path.back()]) {
            path.push_back(nxt);
            dfs(graph, path, res);
            path.pop_back();
        }
    }
};
