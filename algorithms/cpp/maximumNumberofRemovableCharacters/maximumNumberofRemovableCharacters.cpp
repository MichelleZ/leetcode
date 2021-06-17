// Source: https://leetcode.com/problems/maximum-number-of-removable-characters/
// Author: Miao Zhang
// Date:   2021-06-17

class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int ns = s.length();
        int np = p.length();
        int n = removable.size();

        auto check = [&] (int m) {
            vector<int> state(ns, 1);
            for (int i = 0; i < m; i++) {
                state[removable[i]] = 0;
            }
            int j = 0;
            for (int i = 0; i < ns; i++) {
                if (state[i] && s[i] == p[j]) {
                    j++;
                    if (j == np) return true;
                }
            }
            return false;
        };

        int l = 0, r = n + 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (check(mid)) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l - 1;
    }
};
