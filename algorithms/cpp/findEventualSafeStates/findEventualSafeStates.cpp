// Source: https://leetcode.com/problems/find-eventual-safe-states/
// Author: Miao Zhang
// Date:   2021-03-12

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<State> states(graph.size(), UNKNOWN);
        vector<int> res;
        for (int i = 0; i < graph.size(); i++) {
            if (dfs(graph, i, states) == SAFE) res.push_back(i);
        }
        return res;
    }

private:
    enum State {UNKNOWN, VISITING, SAFE, UNSAFE};
    State dfs(const vector<vector<int>>& g, int cur, vector<State>& states) {
        if (states[cur] == VISITING) return states[cur] = UNSAFE;
        if (states[cur] != UNKNOWN) return states[cur];
        states[cur] = VISITING;
        for (int nxt: g[cur]) {
            if (dfs(g, nxt, states) == UNSAFE) return states[cur] = UNSAFE;
        }
        return states[cur] = SAFE;
    }
};
