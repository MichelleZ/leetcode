// Source: https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/
// Author: Miao Zhang
// Date:   2021-04-23

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> nums(ranges.size());
        for (int i = 0; i <= n; i++) {
            int s = max(0, i - ranges[i]);
            nums[s] = i + ranges[i];
        }
        // refer lc45
        int res = 0;
        int lastend = 0;
        int end = 0;
        for (int i = 0; i <= n; i++) {
            if (i > end) return -1;
            if (i > lastend) {
                res++;
                lastend = end;
            }
            end = max(end, nums[i]);
        }
        return res;
    }
};
