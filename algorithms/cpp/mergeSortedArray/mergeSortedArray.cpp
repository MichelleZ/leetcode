// Source: https://leetcode.com/problems/merge-sorted-array/
// Author: Miao Zhang
// Date:   2021-01-15

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        while (m > 0 && n > 0) {
            if (nums1[m - 1] < nums2[n - 1]) {
                nums1[m + n - 1] = nums2[n - 1];
                n--;
            } else {
                swap(nums1[m - 1], nums1[m + n - 1]);
                m--;
            }
        }
        while (m == 0 && n > 0) {
            nums1[n - 1] = nums2[n - 1];
            n--;
        }
    }
};
