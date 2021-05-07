// Source: https://leetcode.com/problems/find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows/
// Author: Miao Zhang
// Date:   2021-05-07

class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        priority_queue<vector<int>> q;
        vector<int> node(m + 1);
        int cursum = 0;
        for (int i = 0; i < m; i++) {
            cursum += mat[i][0];
        }
        node[0] -= cursum;
        q.push(node);
        set<vector<int>> seen{node};
        while (!q.empty()) {
            vector<int> cur = q.top();
            q.pop();
            if (--k == 0) return -cur[0];
            for (int i = 0; i < m; i++) {
                if (cur[i + 1] == n - 1) continue;
                vector<int> nxt(cur);
                nxt[i + 1]++;
                nxt[0] -= (mat[i][nxt[i + 1]] - mat[i][nxt[i + 1] - 1]);
                if (!seen.count(nxt)) {
                    seen.insert(nxt);
                    q.push(move(nxt));
                }
            }
        }
        return -1;
    }
};
