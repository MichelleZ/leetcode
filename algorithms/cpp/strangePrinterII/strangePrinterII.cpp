// Source: https://leetcode.com/problems/strange-printer-ii/
// Author: Miao Zhang
// Date:   2021-05-19

class Solution {
public:
    bool isPrintable(vector<vector<int>>& targetGrid) {
        int maxc = 60;
        int m = targetGrid.size();
        int n = targetGrid[0].size();
        vector<unordered_set<int>> insides(maxc + 1);
        for (int c = 1; c <= maxc; c++) {
            int l = n, r = -1, t = m, b = -1;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (targetGrid[i][j] == c) {
                        l = min(l, j), r = max(r, j), t = min(t, i), b = max(b, i);
                    }
                }
            }
            if (l == -1) continue;
            for (int i = t; i <= b; i++) {
                for (int j = l; j <= r; j++) {
                    if (targetGrid[i][j] != c) {
                        insides[c].insert(targetGrid[i][j]);
                    }
                }
            }
        }
        vector<int> seen(maxc + 1);

        function<bool(int)> hasCycle = [&] (int c) {
            if (seen[c] == 1) return true;
            if (seen[c] == 2) return false;
            seen[c] = 1;
            for (int c2: insides[c]) {
                if (hasCycle(c2)) return true;
            }
            seen[c] = 2;
            return false;
        };

        for (int c = 1; c <= maxc; c++) {
            if (hasCycle(c)) return false;
        }
        return true;
    }
};
