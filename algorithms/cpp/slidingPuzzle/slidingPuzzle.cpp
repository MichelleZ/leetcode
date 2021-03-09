// Source: https://leetcode.com/problems/sliding-puzzle/
// Author: Miao Zhang
// Date:   2021-03-09

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        string goal;
        string start;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                start += (board[i][j] + '0');
                goal += (i * n + j + 1) % (m * n) + '0'; // 123450
            }
        }

        if (start == goal) return 0;
        vector<vector<int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        set<string> visited{start};
        int steps = 0;
        queue<string> q;
        q.push(start);
        while (!q.empty()) {
            steps++;
            int size = q.size();
            while (size-- > 0) {
                string s = q.front();
                q.pop();
                int p = s.find('0');
                int x = p / n;
                int y = p % n;
                for (auto d: dirs) {
                    int nx = x + d[0];
                    int ny = y + d[1];
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                    int pp = nx * n + ny;
                    string t(s);
                    swap(t[p], t[pp]);
                    if (visited.count(t)) continue;
                    if (t == goal) return steps;
                    visited.insert(t);
                    q.push(t);
                }
            }
        }
        return -1;
    }
};
