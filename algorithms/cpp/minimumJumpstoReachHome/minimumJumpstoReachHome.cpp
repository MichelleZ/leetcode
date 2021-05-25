// Source: https://leetcode.com/problems/minimum-jumps-to-reach-home/
// Author: Miao Zhang
// Date:   2021-05-25

class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        int kMaxPos = 6000;
        if (x == 0) return 0;
        queue<pair<int, bool>> q;
        q.push({0, true});
        unordered_set<int> seen1, seen2;
        for (int f: forbidden) {
            seen1.insert(f);
            seen2.insert(f);
        }
        seen1.insert(0);
        int steps = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [cur, dir] = q.front(); q.pop();
                if (cur == x) return steps;
                if (cur > kMaxPos) continue;
                if (seen1.insert(cur + a).second) {
                    q.emplace(cur + a, true);
                }
                if (cur - b >= 0 && dir && seen2.insert(cur - b).second) {
                    q.emplace(cur - b, false);
                }
            }
            steps++;
        }
        return -1;
    }
};
