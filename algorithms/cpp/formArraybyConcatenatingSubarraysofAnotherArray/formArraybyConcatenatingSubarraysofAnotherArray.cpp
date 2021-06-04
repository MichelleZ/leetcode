// Source: https://leetcode.com/problems/form-array-by-concatenating-subarrays-of-another-array/
// Author: Miao Zhang
// Date:   2021-06-04

class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        for (auto& g: groups) {
            bool found = false;
            for (int i = s; i <= n - g.size(); i++) {
                if (equal(begin(g), end(g), begin(nums) + i)) {
                    s = i + g.size();
                    found = true;
                    break;
                }
            }
            if (!found) return false;
        }
        return true;
    }
};
