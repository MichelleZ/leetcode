// Source: https://leetcode.com/problems/bulb-switcher-ii/
// Author: Miao Zhang
// Date:   2021-02-28

class Solution {
public:
    int flipLights(int n, int m) {
        if (n > 6) n = n % 6 + 6;
        unordered_set<int> s1{(1 << n) - 1};
        auto flip = [n](int s, int start, int step) {
            for (int i = start; i < n; i += step) {
                s ^= (1 << i);
            }
            return s;
        };
        for (int i = 0; i < m; i++) {
            unordered_set<int> s2;
            for (int s: s1) {
                s2.insert(flip(s, 0, 1));
                s2.insert(flip(s, 0, 2));
                s2.insert(flip(s, 1, 2));
                s2.insert(flip(s, 0, 3));
            }
            s1.swap(s2);
        }
        return s1.size();
    }
};
