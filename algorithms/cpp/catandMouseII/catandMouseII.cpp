// Source: https://leetcode.com/problems/cat-and-mouse-ii/
// Author: Miao Zhang
// Date:   2021-06-01

class Solution {
public:
    bool canMouseWin(vector<string>& grid, int catJump, int mouseJump) {
        int m = grid.size();
        int n = grid[0].size();
        CatJump = catJump;
        MouseJump = mouseJump;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'F') {
                    food = {i, j};
                }
                if (grid[i][j] == 'M') {
                    mouse = {i, j};
                }
                if (grid[i][j] == 'C') {
                    cat = {i, j};
                }
            }
        }
        queue<array<int, 5>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int t = 1; t <= 2; t++) {
                    if (grid[i][j] == '#') continue;
                    if (i == food.first && j == food.second) continue;
                    memo[i][j][food.first][food.second][t] = 2;
                    memo[food.first][food.second][i][j][t] = 1;
                    q.push({i, j, food.first, food.second, t});
                    q.push({food.first, food.second, i, j, t});
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int t = 1; t <= 2; t++) {
                    if (grid[i][j] == '#') continue;
                    memo[i][j][i][j][t] = 2;
                    q.push({i, j, i, j, t});
                }
            }
        }
        int steps = 0;
        while (!q.empty()) {
            steps++;
            if (steps > 2000) return false;
            int len = q.size();
            while (len--) {
                int mx = q.front()[0];
                int my = q.front()[1];
                int cx = q.front()[2];
                int cy = q.front()[3];
                int t = q.front()[4];
                int status = memo[mx][my][cx][cy][t];
                q.pop();
                for (auto nxt: findAllAdjacents(mx, my, cx, cy, t, grid)) {
                    int mx2 = nxt[0];
                    int my2 = nxt[1];
                    int cx2 = nxt[2];
                    int cy2 = nxt[3];
                    int t2 = nxt[4];
                    if (memo[mx2][my2][cx2][cy2][t2]) continue;
                    if (t2 == status) {
                        memo[mx2][my2][cx2][cy2][t2] = status;
                        q.push({mx2, my2, cx2, cy2, t2});
                    } else if (allAdjacentsWin(mx2, my2, cx2, cy2, t2, grid)) {
                        memo[mx2][my2][cx2][cy2][t2] = (t2 == 1) ? 2: 1;
                        q.push({mx2, my2, cx2, cy2, t2});
                    }
                }
            }
        }
        return memo[mouse.first][mouse.second][cat.first][cat.second][1] == 1;
    }

    vector<array<int, 5>> findAllAdjacents(int mx, int my, int cx, int cy, int t, vector<string>& grid) {
        vector<array<int, 5>> res;
        auto dir = vector<pair<int, int>>({{1, 0}, {-1, 0}, {0, 1}, {0, -1}});
        int m = grid.size();
        int n = grid[0].size();
        if (t == 1) {
            for (int k = 0; k < 4; k++) {
                for (int a = 0; a <= CatJump; a++) {
                    int cx2 = cx + dir[k].first * a;
                    int cy2 = cy + dir[k].second * a;
                    if (cx2 < 0 || cx2 >= m || cy2 < 0 || cy2 >= n) continue;
                    if (grid[cx2][cy2] == '#') break;
                    res.push_back({mx, my, cx2, cy2, 2});
                }
            }
        }
        if (t == 2) {
            for (int k = 0; k < 4; k++) {
                for (int a = 0; a <= MouseJump; a++) {
                    int mx2 = mx + dir[k].first * a;
                    int my2 = my + dir[k].second * a;
                    if (mx2 < 0 || mx2 >= m || my2 < 0 || my2 >= n) continue;
                    if (grid[mx2][my2] == '#') break;
                    res.push_back({mx2, my2, cx, cy, 1});
                }
            }
        }
        return res;
    }

    bool allAdjacentsWin(int mx, int my, int cx, int cy, int t, vector<string>& grid) {
        auto dir = vector<pair<int, int>>({{1, 0}, {-1, 0}, {0, 1}, {0, -1}});
        int m = grid.size();
        int n = grid[0].size();
        if (t == 1) {
            for (int k = 0; k < 4; k++) {
                for (int a = 0; a <= MouseJump; a++) {
                    int mx2 = mx + dir[k].first * a;
                    int my2 = my + dir[k].second * a;
                    if (mx2 < 0 || mx2 >= m || my2 < 0 || my2 >= n) continue;
                    if (grid[mx2][my2] == '#') break;
                    if (memo[mx2][my2][cx][cy][2] != 2)
                        return false;
                }
            }
        }
        if (t == 2) {
            for (int k = 0; k < 4; k++) {
                for (int a = 0; a <= CatJump; a++) {
                    int cx2 = cx + dir[k].first * a;
                    int cy2 = cy + dir[k].second * a;
                    if (cx2 < 0 || cx2 >= m || cy2 < 0 || cy2 >= n) continue;
                    if (grid[cx2][cy2] == '#') break;
                    if (memo[mx][my][cx2][cy2][1] != 1)
                        return false;
                }
            }
        }
        return true;
    }

private:
    // (m, c, t)
    int memo[9][9][9][9][3];
    pair<int, int> food;
    pair<int, int> mouse;
    pair<int, int> cat;
    int CatJump;
    int MouseJump;
};
