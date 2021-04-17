// Source: https://leetcode.com/problems/unique-number-of-occurrences/
// Author: Miao Zhang
// Date:   2021-04-17

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> cnt;
        for (auto a: arr) cnt[a]++;
        unordered_set<int> s;
        for (const auto& kv: cnt) {
            if (!s.insert(kv.second).second) {
                return false;
            }
        }
        return true;
    }
};
