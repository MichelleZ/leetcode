// Source: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
// Author: Miao Zhang
// Date:   2021-01-07

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int start = 0, end = 0;
        vector<int> res;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) {
                start = mid;
                end = mid;
                while (start >= 0 && nums[start] == target) start--;
                while (end < nums.size() && nums[end] == target) end++;
                res.push_back(start + 1);
                res.push_back(end - 1);
                return res;
            } else if (nums[mid] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        res.push_back(-1);
        res.push_back(-1);
        return res;
    }
};
