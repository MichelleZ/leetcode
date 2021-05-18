// Source: https://leetcode.com/problems/number-of-ways-where-square-of-number-is-equal-to-product-of-two-numbers/
// Author: Miao Zhang
// Date:   2021-05-18

class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        return solve(nums1, nums2) + solve(nums2, nums1);
    }

private:
    int solve(vector<int>& nums1, vector<int>& nums2) {
        int res = 0;
        unordered_map<int, int> cnt;
        for (int n2: nums2) cnt[n2]++;
        for (long n1: nums1) {
            for (const auto& [n2, c]: cnt) {
                long r = n1 * n1 / n2;
                if (n1 * n1 % n2 || !cnt.count(r)) continue;
                if (r == n2) {
                    res += c * (c - 1);
                } else {
                    res += c * cnt[r];
                }
            }
        }
        return res / 2;
    }
};
