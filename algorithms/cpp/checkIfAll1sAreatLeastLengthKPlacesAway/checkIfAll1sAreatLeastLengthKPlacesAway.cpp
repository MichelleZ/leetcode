// Source: https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/
// Author: Miao Zhang
// Date:   2021-05-07

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int d = k + 1;
        for (int n: nums) {
            if (n == 0) {
                d++;
            } else {
                if (d < k) return false;
                d = 0;
            }
        }
        return true;
    }
};
