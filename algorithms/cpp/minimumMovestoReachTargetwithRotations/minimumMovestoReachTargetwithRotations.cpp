// Source: https://leetcode.com/problems/minimum-moves-to-reach-target-with-rotations/
// Author: Miao Zhang
// Date:   2021-04-17

class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_set<int> seen;
        queue<pair<int, int>> q;
        q.push({pos(0, 0), pos(0, 1)});
        seen.insert(encode(pos(0, 0), pos(0, 1)));
        int steps = 0;
        auto valid = [&](int x, int y) {
            return x >= 0 && x < n && y >= 0 && y < n && !grid[x][y];
        };
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto p = q.front();
                q.pop();
                int x1 = p.first / 100;
                int y1 = p.first % 100;
                int x2 = p.second / 100;
                int y2 = p.second % 100;
                if (x1 == n - 1 and y1 == n - 2 and x2 == n - 1 and y2 == n - 1) {
                    return steps;
                }

                bool rotatedir = x1 == x2; // clockwise
                for (int i = 0; i < 3; i++) {
                    int tx1 = x1;
                    int ty1 = y1;
                    int tx2 = x2;
                    int ty2 = y2;
                    int rx = x1;
                    int ry = y1;
                    if (i == 0) { // down
                        tx1++;
                        tx2++;
                    } else if (i == 1) { // right
                        ty1++;
                        ty2++;
                    } else { // rotate
                        rx++;
                        ry++;
                        if (rotatedir) {
                            tx2++;
                            ty2--;
                        } else {
                            tx2--;
                            ty2++;
                        }
                    }
                    if (!valid(tx1, ty1) || !valid(tx2, ty2) || !valid(rx, ry)) continue;
                    int key = encode(pos(tx1, ty1), pos(tx2, ty2));
                    if (seen.count(key)) continue;
                    seen.insert(key);
                    q.push({pos(tx1, ty1), pos(tx2, ty2)});
                }
            }
            steps++;
        }
        return -1;
    }

private:
    int pos(int i, int j) {
        return i * 100 + j;
    }

    int encode(int p1, int p2) {
        return (p1 << 16) | p2;
    }
};
