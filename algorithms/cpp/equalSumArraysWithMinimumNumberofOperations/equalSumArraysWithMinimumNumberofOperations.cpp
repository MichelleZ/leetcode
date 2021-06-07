// Source: https://leetcode.com/problems/equal-sum-arrays-with-minimum-number-of-operations/
// Author: Miao Zhang
// Date:   2021-06-07

class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int l1 = nums1.size();
        int l2 = nums2.size();
        if (min(l1, l2) * 6 < max(l1, l2) * 1) return -1;
        int s1 = accumulate(begin(nums1), end(nums1), 0);
        int s2 = accumulate(begin(nums2), end(nums2), 0);
        if (s1 > s2) return minOperations(nums2, nums1);
        if (s1 == s2) return 0;
        sort(begin(nums1), end(nums1));
        sort(rbegin(nums2), rend(nums2));
        int res = 0;
        for (int i = 0, j = 0; s1 < s2; res++) {
            int d1 = i == l1 ? 0 : 6 - nums1[i];
            int d2 = j == l2 ? 0 : nums2[j] - 1;
            if (d1 >= d2) {
                s1 += d1;
                i++;
            } else {
                s2 -= d2;
                j++;
            }
        }
        return res;
    }
};
