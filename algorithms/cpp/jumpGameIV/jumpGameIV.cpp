// Source: https://leetcode.com/problems/jump-game-iv/
// Author: Miao Zhang
// Date:   2021-04-25

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < n; i++)
            m[arr[i]].push_back(i);
        queue<int> q({0});
        vector<int> seen(n);
        seen[0] = 1;
        int steps = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int cur = q.front();
                q.pop();
                if (cur == n - 1) return steps;
                if (cur - 1 >= 0 && !seen[cur - 1]++) q.push(cur - 1);
                if (cur + 1 < n && !seen[cur + 1]++) q.push(cur + 1);
                auto it = m.find(arr[cur]);
                if (it == m.end()) continue;
                for (int nxt: it->second) {
                    if (!seen[nxt]++) q.push(nxt);
                }
                m.erase(it);
            }
            steps++;
        }
        return -1;
    }
};
