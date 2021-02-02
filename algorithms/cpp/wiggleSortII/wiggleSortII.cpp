// Source: https://leetcode.com/problems/wiggle-sort-ii/
// Author: Miao Zhang
// Date:   2021-02-02

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> tmp = nums;
        int n = nums.size();
        sort(tmp.begin(), tmp.end());
        int mid = (n + 1) / 2;
        int j = n;
        for (int i = 0; i < n; i++) {
            nums[i] = i & 1 ? tmp[--j] : tmp[--mid];
        }
    }
};
