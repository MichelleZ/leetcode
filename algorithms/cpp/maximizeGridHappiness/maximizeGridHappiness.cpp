// Source: https://leetcode.com/problems/maximize-grid-happiness/
// Author: Miao Zhang
// Date:   2021-05-26

class Solution {
public:
    int getMaxGridHappiness(int m, int n, int introvertsCount, int extrovertsCount) {
        // 3 ** 5
        int kMaxStates = 243;
        int dp[6][6][7][7][kMaxStates];
        memset(dp, -1, sizeof(dp));
        auto get = [](int val, int i) {
            return val / static_cast<int>(pow(3, i)) % 3;
        };
        auto update = [&](int val, int s) {
            return (val * 3 + s) % kMaxStates;
        };
        vector<int> init{0, 120, 40};
        vector<int> gain{0, -30, 20};

        function<int(int,int,int,int,int)> dfs = [&](int x, int y, int in, int ex, int mask) {
            if (y == n) {
                x++;
                y = 0;
            }
            if (x == m) return 0;
            if (in == 0 && ex == 0) return 0;
            int& res = dp[x][y][in][ex][mask];
            if (res != -1) return res;
            res = dfs(x, y + 1, in, ex, update(mask, 0));
            vector<int> counts{0, in, ex};
            int up = get(mask, n - 1);
            int left = get(mask, 0);
            for (int i = 1; i <= 2; ++i) {
                if (counts[i] == 0) continue;
                int s = init[i];
                if (y - 1 >= 0 && left) s += gain[i] + gain[left];
                if (x - 1 >= 0 && up) s += gain[i] + gain[up];
                res = max(res, s + dfs(x, y + 1, in - (i==1), ex - (i==2), update(mask, i)));
            }
            return res;
        };
        return dfs(0, 0, introvertsCount, extrovertsCount, 0);
    }
};
