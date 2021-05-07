// Source: https://leetcode.com/problems/number-of-ways-of-cutting-a-pizza/
// Author: Miao Zhang
// Date:   2021-05-07

class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        int kMod = 1e9 + 7;
        int m = pizza.size();
        int n = pizza[0].size();

        vector<vector<int>> calapp(m + 1, vector<int>(n + 1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                calapp[i + 1][j + 1] = calapp[i + 1][j] + calapp[i][j + 1] + (pizza[i][j] == 'A') - calapp[i][j];
            }
        }

        auto hasApples = [&] (int x1, int y1, int x2, int y2) {
            return (calapp[x2 + 1][y2 + 1] - calapp[x2 + 1][y1] - calapp[x1][y2 + 1] + calapp[x1][y1]) > 0;
        };

        vector<vector<vector<int>>> cache(m, vector<vector<int>>(n, vector<int>(k, -1)));
        function<int(int, int, int)> dp = [&] (int x, int y, int s) -> int {
            if (s == 0) return hasApples(x, y, m - 1, n - 1);
            int& res = cache[x][y][s];
            if (res != -1) return res;
            res = 0;
            for (int i = x; i < m - 1; i++) {
                res = (res + hasApples(x, y, i, n - 1) * dp(i + 1, y, s - 1)) % kMod;
            }
            for (int j = y; j < n - 1; j++) {
                res = (res + hasApples(x, y, m - 1, j) * dp(x, j + 1, s - 1)) % kMod;
            }
            return res;
        };
        return dp(0, 0, k - 1);
    }
};
