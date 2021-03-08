// Source: https://leetcode.com/problems/open-the-lock/
// Author: Miao Zhang
// Date:   2021-03-07

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        string start = "0000";
        if (dead.count(start)) return -1;
        if (start == target) return 0;

        queue<string> q;
        unordered_set<string> visited{start};
        int cnt = 0;
        q.push(start);
        while (!q.empty()) {
            cnt++;
            int n = q.size();
            for (int i = 0; i < n; i++) {
                string node = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    for (int j = -1; j <= 1; j += 2) {
                        string next_node = node;
                        next_node[i] = (next_node[i] - '0' + j + 10) % 10 + '0';
                        if (next_node == target) return cnt;
                        if (dead.count(next_node) || visited.count(next_node)) continue;
                        q.push(next_node);
                        visited.insert(next_node);
                    }
                }
            }
        }
        return -1;
    }
};
