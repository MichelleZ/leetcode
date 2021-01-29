// Source: https://leetcode.com/problems/ugly-number-ii/
// Author: Miao Zhang
// Date:   2021-01-28

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> res{1};
        int i2 = 0;
        int i3 = 0;
        int i5 = 0;
        while (res.size() < n) {
            int next2 = res[i2] * 2;
            int next3 = res[i3] * 3;
            int next5 = res[i5] * 5;
            int nxt = min(next2, min(next3, next5));
            if (nxt == next2) i2++;
            if (nxt == next3) i3++;
            if (nxt == next5) i5++;
            res.push_back(nxt);
        }
        return res[n - 1];
    }
};
