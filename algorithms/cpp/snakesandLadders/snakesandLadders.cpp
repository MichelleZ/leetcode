// Source: https://leetcode.com/problems/snakes-and-ladders/
// Author: Miao Zhang
// Date:   2021-03-23

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int steps = 0;
        vector<int> seen(n * n + 1, 0);
        queue<int> q;
        q.push(1);
        while (!q.empty()) {
            int size = q.size();
            steps++;
            while (size--) {
                int s = q.front();
                q.pop();
                for (int s1 = s + 1; s1 <= min(s + 6, n * n); s1++) {
                    int r, c;
                    get(s1, n, &r, &c);
                    int x = board[r][c] == -1 ? s1 : board[r][c];
                    if (seen[x]) continue;
                    if (x == n * n) return steps;
                    q.push(x);
                    seen[x] = 1;
                }
            }
        }
        return -1;
    }

private:
    void get(int s, int n, int* r, int* c) {
        int x = (s - 1) / n;
        int y = (s - 1) % n;
        *r = n - 1 - x;
        *c = (x % 2) ? n - 1 - y : y;
    }
};
