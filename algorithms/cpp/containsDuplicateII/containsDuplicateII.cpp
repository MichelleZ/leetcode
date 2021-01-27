// Source: https://leetcode.com/problems/contains-duplicate-ii/
// Author: Miao Zhang
// Date:   2021-01-27

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); i++) {
            if (s.find(nums[i]) != s.end()) {
                return true;
            }
            s.insert(nums[i]);
            if (s.size() > k) {
                s.erase(s.find(nums[i - k]));
            }
        }
        return false;
    }
};
