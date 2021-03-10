// Source: https://leetcode.com/problems/possible-bipartition/
// Author: Miao Zhang
// Date:   2021-03-10

class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        graph_ = vector<vector<int>>(N);
        for (const auto& d: dislikes) {
            graph_[d[0] - 1].push_back(d[1] - 1);
            graph_[d[1] - 1].push_back(d[0] - 1);
        }
        colors_ = vector<int>(N, 0);
        for (int i = 0; i < N; i++) {
            if (colors_[i] == 0 && !dfs(i, 1)) return false;
        }
        return true;
    }

private:
    vector<vector<int>> graph_;
    vector<int> colors_;
    
    bool dfs(int cur, int color) {
        colors_[cur] = color;
        for (int nxt: graph_[cur]) {
            if (colors_[nxt] == color) return false;
            if (colors_[nxt] == 0 && !dfs(nxt, -color)) return false;
        }
        return true;
    }
};

class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(N);
        for (const auto& d: dislikes) {
            graph[d[0] - 1].push_back(d[1] - 1);
            graph[d[1] - 1].push_back(d[0] - 1);
        }
        vector<int> colors(N, 0);
        queue<int> q;
        for (int i = 0; i < N; i++) {
            if (colors[i] != 0) continue;
            q.push(i);
            colors[i] = 1;
            while (!q.empty()) {
                int cur = q.front();
                q.pop();
                for (int nxt: graph[cur]) {
                    if (colors[nxt] == colors[cur]) return false;
                    if (colors[nxt] != 0) continue;
                    colors[nxt] = -colors[cur];
                    q.push(nxt);
                }
            }
        }
        return true;
    }
};
