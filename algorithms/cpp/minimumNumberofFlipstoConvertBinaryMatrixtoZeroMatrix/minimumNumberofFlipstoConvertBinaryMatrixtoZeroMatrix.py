// Source: https://leetcode.com/problems/minimum-number-of-flips-to-convert-binary-matrix-to-zero-matrix/
// Author: Miao Zhang
// Date:   2021-04-21

class Solution {
public:
    int minFlips(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> dirs{0, 1, 0, -1, 0, 0};

        auto flip = [&] (int s, int i, int j) {
            for (int k = 0; k < 5; k++) {
                int x = i + dirs[k];
                int y = j + dirs[k + 1];
                if (x < 0 || x >= m || y < 0 || y >= n) continue;
                s ^= (1 << (x * n + y));
            }
            return s;
        };

        int steps = 0;
        queue<int> q;
        vector<int> seen(1 << (m * n));
        int start = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                start |= (mat[i][j] << (i * n + j));
            }
        }
        q.push(start);
        seen[start] = 1;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int s = q.front();
                q.pop();
                if (s == 0) return steps;
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < n; j++) {
                        int t = flip(s, i, j);
                        if (seen[t]) continue;
                        seen[t] = 1;
                        q.push(t);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};
