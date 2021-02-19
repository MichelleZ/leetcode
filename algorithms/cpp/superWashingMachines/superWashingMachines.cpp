// Source: https://leetcode.com/problems/super-washing-machines/
// Author: Miao Zhang
// Date:   2021-02-19

class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int sums = accumulate(machines.begin(), machines.end(), 0);
        if (sums % machines.size() != 0) return -1;
        int res = 0;
        int cnt = 0;
        int avg = sums / machines.size();
        for (int m: machines) {
            cnt += m - avg;
            res = max(res, max(abs(cnt), m - avg));
        }
        return res;
    }
};
