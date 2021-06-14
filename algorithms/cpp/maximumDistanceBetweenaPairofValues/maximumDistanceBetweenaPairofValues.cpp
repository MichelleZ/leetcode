// Source: https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/
// Author: Miao Zhang
// Date:   2021-06-14

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int res = 0;
        for (int i = 0, j = -1; i < nums1.size(); i++) {
            while (j + 1 < nums2.size() && nums2[j + 1] >= nums1[i]) {
                j++;
            }
            if (j >= i) res = max(res, j - i);
        }
        return res;
    }
};
