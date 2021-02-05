// Source: https://leetcode.com/problems/guess-number-higher-or-lower/
// Author: Miao Zhang
// Date:   2021-02-04

class Solution {
public:
    int guessNumber(int n) {
        int l = 0;
        int r = n;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (guess(mid) == 0) {
                return mid;
            } else if (guess(mid) == -1) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return -1;
    }
};
