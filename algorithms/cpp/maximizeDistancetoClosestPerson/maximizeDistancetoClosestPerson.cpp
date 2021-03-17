// Source: https://leetcode.com/problems/maximize-distance-to-closest-person/
// Author: Miao Zhang
// Date:   2021-03-17

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int prev = -1;
        int res = 0;
        for (int i = 0; i <= n; i++) {
            if (i == n) res = max(res, n - prev - 1);
            else if (seats[i]) {
                if (prev == -1) res = i;
                else {
                    res = max(res, (i - prev) / 2);
                }
                prev = i;
            }
        }
        return res;
    }
};
