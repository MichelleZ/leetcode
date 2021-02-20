// Source: https://leetcode.com/problems/minimum-time-difference/
// Author: Miao Zhang
// Date:   2021-02-20

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int kMins = 24 * 60;
        set<int> minset;
        for (auto t: timePoints) {
            int m = stoi(t.substr(0, 2)) * 60 + stoi(t.substr(3));
            if (!minset.insert(m).second) return 0;
        }
        
        int res = (*minset.begin() - *minset.rbegin() + kMins) % kMins;
        const int* pre = nullptr;
        for (auto& t: minset) {
            if (pre) res = min(res, t - *pre);
            pre = &t;
        }
        return res;
    }
};
