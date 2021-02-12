// Source: https://leetcode.com/problems/find-all-duplicates-in-an-array/
// Author: Miao Zhang
// Date:   2021-02-11

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        if (nums.empty()) return res;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[abs(nums[i]) - 1] < 0) {
                res.push_back(abs(nums[i]));
            }
            nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
        }
        return res;
    }
};
