// Source: https://leetcode.com/problems/minimum-operations-to-make-a-subsequence/
// Author: Miao Zhang
// Date:   2021-05-31

class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> m;
        for (int i = 0; i < target.size(); i++) {
            m[target[i]] = i;
        }
        vector<int> dp;
        for (int& a: arr) {
            auto it = m.find(a);
            if (it == m.end()) continue;
            int idx = it->second;
            if (dp.empty() || idx > dp.back()) {
                dp.push_back(idx);
            }
            else {
                *lower_bound(begin(dp), end(dp), idx) = idx;
            }
        }
        return target.size() - dp.size();
    }
};
