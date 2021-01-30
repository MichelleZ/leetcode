// Source: https://leetcode.com/problems/find-the-duplicate-number/
// Author: Miao Zhang
// Date:   2021-01-30

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) break;
        }
        int find = 0;
        while (find != slow) {
            find = nums[find];
            slow = nums[slow];
        }
        return find;
    }
};
