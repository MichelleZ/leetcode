// Source: https://leetcode.com/problems/single-threaded-cpu/
// Author: Miao Zhang
// Date:   2021-06-10

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        for (int i = 0; i < n; i++) {
            tasks[i].push_back(i);
        }
        sort(begin(tasks), end(tasks));
        vector<int> res;
        priority_queue<pair<int, int>> q; // {-processtime, -index}
        int i = 0;
        long cur = 0;
        while (res.size() != n) {
            if (i < n && q.empty() && tasks[i][0] > cur) {
                cur = tasks[i][0];
            }
            while (i < n && tasks[i][0] <= cur) {
                q.emplace(-tasks[i][1], -tasks[i][2]);
                i++;
            }
            cur -= q.top().first;
            res.push_back(-q.top().second);
            q.pop();
        }
        return res;
    }
};
