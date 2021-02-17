// Source: https://leetcode.com/problems/reverse-pairs/
// Author: Miao Zhang
// Date:   2021-02-17

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }

private:
    int mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) return 0;
        int mid = left + (right - left) / 2;
        int res = mergeSort(nums, left, mid) + mergeSort(nums, mid + 1, right);
        int i = left, j = mid + 1;
        while (i <= mid && j <= right) {
            if (nums[i] / 2.0 > nums[j]) {
                res += mid - i + 1;
                j++;
            } else {
                i++;
            }
        }
        sort(nums.begin() + left, nums.begin() + right + 1);
        return res;
    }
};
