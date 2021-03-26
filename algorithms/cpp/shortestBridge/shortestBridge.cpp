// Source: https://leetcode.com/problems/shortest-bridge/
// Author: Miao Zhang
// Date:   2021-03-26

class Solution {
public:
    int shortestBridge(vector<vector<int>>& A) {
        queue<pair<int, int>> q;
        bool found = false;
        for (int i = 0; i < A.size() && !found; i++) {
            for (int j = 0; j < A[0].size() && !found; j++) {
                if (A[i][j]) {
                    dfs(A, i, j, q);
                    found = true;
                }
            }
        }
        
        int step = 0;
        vector<vector<int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                for (auto& d: dirs) {
                    int x = i + d[0];
                    int y = j + d[1];
                    if (x < 0 || x >= A.size() || y < 0 || y >= A[0].size() || A[x][y] == -1) continue;
                    if (A[x][y] == 1) return step;
                    A[x][y] = -1;
                    q.emplace(x, y);
                }
            }
            step++;
        }
        return -1;
    }

private:
    void dfs(vector<vector<int>>& A, int i, int j, queue<pair<int, int>>& q) {
        if (i < 0 or i >= A.size() or j < 0 or j >= A[0].size() || A[i][j] != 1) return;
        A[i][j] = -1;
        q.emplace(i, j);
        dfs(A, i - 1, j, q);
        dfs(A, i + 1, j, q);
        dfs(A, i, j - 1, q);
        dfs(A, i, j + 1, q);
    }
};
