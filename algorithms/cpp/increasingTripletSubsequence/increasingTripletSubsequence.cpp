// Source: https://leetcode.com/problems/increasing-triplet-subsequence/
// Author: Miao Zhang
// Date:   2021-02-03

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX;
        int second = INT_MAX;
        for (auto &n: nums) {
            if (n <= first) {
                first = n;
            } else if (n <= second) {
                second = n;
            } else {
                return true;
            }
        }
        return false;
    }
};
