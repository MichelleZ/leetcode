// Source: https://leetcode.com/problems/find-servers-that-handled-most-number-of-requests/
// Author: Miao Zhang
// Date:   2021-05-20

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
        set<int> servers;
        vector<int> requests(k);

        for (int i = 0; i < k; i++) {
            servers.insert(i);
        }

        for (int i = 0; i < arrival.size(); i++) {
            int start = arrival[i];
            int duration = load[i];
            while (!q.empty() && q.top().first <= start) {
                servers.insert(q.top().second);
                q.pop();
            }
            if (servers.empty()) continue;
            auto it = servers.lower_bound(i % k);
            if (it == servers.end()) {
                it = begin(servers);
            }
            int idx = *it;
            requests[idx]++;
            servers.erase(it);
            q.emplace(start + duration, idx);
        }
        int maxres = *max_element(begin(requests), end(requests));
        vector<int> res;
        for (int i = 0; i < requests.size(); i++) {
            if (requests[i] == maxres)
                res.push_back(i);
        }
        return res;
    }
};
