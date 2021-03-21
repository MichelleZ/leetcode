// Source: https://leetcode.com/problems/reachable-nodes-in-subdivided-graph/
// Author: Miao Zhang
// Date:   2021-03-21

class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<vector<pair<int, int>>> graph(n);
        for (const auto& e: edges) {
            graph[e[0]].emplace_back(e[1], e[2]);
            graph[e[1]].emplace_back(e[0], e[2]);
        }
        // moves num, node
        priority_queue<pair<int, int>> q;
        unordered_map<int, int> moves;
        q.push({maxMoves, 0});
        while (!q.empty()) {
            int move = q.top().first;
            int cur = q.top().second;
            q.pop();
            if (moves.count(cur)) continue;
            moves[cur] = move;
            for (const auto& g: graph[cur]) {
                int nxt = g.first;
                int nxt_move = move - g.second - 1;
                if (moves.count(nxt) || nxt_move < 0) continue;
                q.push({nxt_move, nxt});
            }
        }
        int res = moves.size();
        for (auto& e: edges) {
            int uv = moves.count(e[0]) ? moves[e[0]] : 0;
            int vu = moves.count(e[1]) ? moves[e[1]] : 0;
            res += min(e[2], uv + vu);
        }
        return res;
    }
};
