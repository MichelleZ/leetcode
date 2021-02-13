// Source: https://leetcode.com/problems/minimum-moves-to-equal-array-elements/
// Author: Miao Zhang
// Date:   2021-02-13

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int res = 0;
        int minVal = *min_element(nums.begin(), nums.end());
        for (auto n: nums) {
            res += n - minVal;
        }
        return res;
    }
};
