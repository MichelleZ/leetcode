// Source: https://leetcode.com/problems/jump-game-iii/
// Author: Miao Zhang
// Date:   2021-04-22

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        queue<int> q;
        q.push(start);
        vector<int> seen(n);
        seen[start] = 1;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            if (arr[cur] == 0) return true;
            for (int i: {-1, 1}) {
                int nxt = cur + i * arr[cur];
                if (nxt < 0 || nxt >= n || seen[nxt]) continue;
                seen[nxt] = 1;
                q.push(nxt);
            }
        }
        return false;
    }
};
