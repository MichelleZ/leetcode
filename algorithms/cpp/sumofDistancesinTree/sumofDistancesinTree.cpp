// Source: https://leetcode.com/problems/sum-of-distances-in-tree/
// Author: Miao Zhang
// Date:   2021-03-16

class Solution {
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        N_ = N;
        res = vector<int>(N, 0);
        count = vector<int>(N, 1);
        graph = vector<vector<int>>(N);
        for (auto& edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        dfs(0, -1);
        dfs2(0, -1);
        return res;
    }

private:
    vector<int> res;
    vector<int> count;
    vector<vector<int>> graph;
    int N_;

    void dfs(int node, int parent) {
        for (int child: graph[node]) {
            if (child != parent) {
                dfs(child, node);
                count[node] += count[child];
                res[node] += res[child] + count[child];
            }
        }
    }

    void dfs2(int node, int parent) {
        for (int child: graph[node]) {
            if (child != parent) {
                res[child] = res[node] - count[child] + N_ - count[child];
                dfs2(child, node);
            }
        }
    }
};
