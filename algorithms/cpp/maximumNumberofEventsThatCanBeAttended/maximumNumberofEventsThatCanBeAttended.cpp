// Source: https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/
// Author: Miao Zhang
// Date:   2021-04-26

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(begin(events), end(events), [](const auto& a, const auto& b) {
            return a[1] < b[1];
        });
        int res = 0;
        int seen[100001] = {0};
        for (auto& e: events) {
            for (int i = e[0]; i <= e[1]; i++) {
                if (seen[i]) continue;
                seen[i]++;
                res++;
                break;
            }
        }
        return res;
    }
};

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(begin(events), end(events), [] (const auto& a, const auto& b) {
            return a[1] < b[1];
        });
        int mind = INT_MAX;
        int maxd = INT_MIN;
        for (const auto& e: events) {
            mind = min(mind, e[0]);
            maxd = max(maxd, e[1]);
        }
        vector<int> days(maxd - mind + 1);
        iota(begin(days), end(days), mind);
        set<int> s(begin(days), end(days));
        int res = 0;
        for (const auto& e: events) {
            auto it = s.lower_bound(e[0]);
            if (it == end(s) || *it > e[1]) continue;
            s.erase(it);
            res++;
        }
        return res;
    }
};
