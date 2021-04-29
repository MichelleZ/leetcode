// Source: https://leetcode.com/problems/find-lucky-integer-in-an-array/
// Author: Miao Zhang
// Date:   2021-04-29

class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> cnt;
        for (auto& a: arr) cnt[a]++;
        int res = -1;
        for (const auto& [k, v]: cnt) {
            if (k == v) res = max(res, k);
        }
        return res;
    }
};
