// Source: https://leetcode.com/problems/optimal-division/
// Author: Miao Zhang
// Date:   2021-02-22

class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        string res = to_string(nums[0]);
        if (nums.size() == 1) return res;
        else if (nums.size() == 2) return res + "/" + to_string(nums[1]);

        res += "/(" + to_string(nums[1]);
        for (int i = 2; i < nums.size(); i++) {
            res += "/" + to_string(nums[i]);
        }
        res += ")";
        return res;
    }
};
