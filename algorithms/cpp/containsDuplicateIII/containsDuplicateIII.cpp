// Source: https://leetcode.com/problems/contains-duplicate-iii/
// Author: Miao Zhang
// Date:   2021-01-27

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multiset<long> mset;   // automatic sort
        for (int i = 0; i < nums.size(); i++) {
            if (i > k) mset.erase(mset.find(nums[i - k - 1]));
            auto it = mset.insert(nums[i]);
            if (it != begin(mset) && *it - *prev(it) <= t) return true;
            if (next(it) != end(mset) && *next(it) - *it <= t) return true;
        }
        return false;
    }
};
