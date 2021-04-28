// Source: https://leetcode.com/problems/create-target-array-in-the-given-order/
// Author: Miao Zhang
// Date:   2021-04-28

class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            res.insert(begin(res) + index[i], nums[i]);
        }
        return res;
    }
};
