// Source: https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
// Author: Miao Zhang
// Date:   2021-02-12

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int index = abs(nums[i]) - 1;
            if (nums[index] > 0) nums[index] = -nums[index];
        }
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                res.push_back(i + 1);
            }
        }
        return res;
    }
};
