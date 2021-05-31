// Source: https://leetcode.com/problems/count-good-meals/
// Author: Miao Zhang
// Date:   2021-05-31

class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        int kMod = 1e9 + 7;
        unordered_map<int, int> m;
        long res = 0;
        for (int d: deliciousness) {
            for (int p = 1; p <= 1 << 21; p *= 2) {
                auto it = m.find(p - d);
                if (it != m.end()) res += it->second;
            }
            m[d]++;
        }
        return res % kMod;
    }
};
