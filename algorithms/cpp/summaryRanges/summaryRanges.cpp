// Source: https://leetcode.com/problems/summary-ranges/
// Author: Miao Zhang
// Date:   2021-01-28

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int l = 0;
        vector<string> res;
        for (int i = 1; i <= nums.size(); i++) {
            if (i == nums.size() || nums[i] != nums[i - 1] + 1) {
                if (l == i - 1) {
                    res.push_back(to_string(nums[l]));
                } else {
                    res.push_back(to_string(nums[l]) + "->" + to_string(nums[i - 1]));
                }
                l = i;
            }
        }
        return res;
    }
};
