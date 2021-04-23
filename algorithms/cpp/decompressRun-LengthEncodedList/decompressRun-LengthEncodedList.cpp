// Source: https://leetcode.com/problems/decompress-run-length-encoded-list/
// Author: Miao Zhang
// Date:   2021-04-23

class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); i += 2) {
            for (int j = 0; j < nums[i]; j++) {
                res.push_back(nums[i + 1]);
            }
        }
        return res;
    }
};
