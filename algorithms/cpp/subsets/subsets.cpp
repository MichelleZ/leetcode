// Source: https://leetcode.com/problems/subsets/
// Author: Miao Zhang
// Date:   2021-01-14

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res(1);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            int res_size = res.size();
            for (int j = 0; j < res_size; j++) {
                res.push_back(res[j]);
                res.back().push_back(nums[i]);
            }
        }
        return res;
    }
};
