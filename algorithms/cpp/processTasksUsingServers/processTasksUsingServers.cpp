// Source: https://leetcode.com/problems/process-tasks-using-servers/
// Author: Miao Zhang
// Date:   2021-06-16

class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int m = servers.size();
        int n = tasks.size();
        // t, idx
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busy;
        // w, idx
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> idle;
        for (int i = 0; i < m; i++) {
            idle.emplace(servers[i], i);
        }
        long long ts = 0;
        auto release = [&]() {
            while (!busy.empty() && busy.top().first <= ts) {
                auto& [_, idx] = busy.top();
                idle.emplace(servers[idx], idx);
                busy.pop();
            }
        };
        
        vector<int> res;
        for (int i = 0; i < n; i++) {
            ts = max(ts, static_cast<long long>(i));
            release();
            if (idle.empty()) {
                ts = busy.top().first;
                release();
            }
            auto& [_, idx] = idle.top();
            res.push_back(idx);
            busy.emplace(ts + tasks[i], idx);
            idle.pop();
        }
        return res;
    }
};
