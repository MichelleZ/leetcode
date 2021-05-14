// Source: https://leetcode.com/problems/get-the-maximum-score/
// Author: Miao Zhang
// Date:   2021-05-14

class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int kMod = 1e9 + 7;
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<long> dp1(n1 + 1);
        vector<long> dp2(n2 + 1);
        int i = 0;
        int j = 0;
        while (i < n1 || j < n2) {
            if (i < n1 && j < n2 && nums1[i] == nums2[j]) {
                dp1[i + 1] = dp2[j + 1] = max(dp1[i], dp2[j]) + nums1[i];
                i += 1;
                j += 1;
            } else if (i < n1 && (j == n2 || nums1[i] < nums2[j])) {
                dp1[i + 1] = dp1[i] + nums1[i];
                i += 1;
            } else if (j < n2 && (i == n1 || nums2[j] < nums1[i])) {
                dp2[j + 1] = dp2[j] + nums2[j];
                j += 1;
            }
        }
        return max(dp1.back(), dp2.back()) % kMod;
    }
};
