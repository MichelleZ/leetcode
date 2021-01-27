// Source: https://leetcode.com/problems/contains-duplicate/
// Author: Miao Zhang
// Date:   2021-01-27

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (const auto& num: nums) {
            s.insert(num);
        }
        return s.size() != nums.size();
    }
};
