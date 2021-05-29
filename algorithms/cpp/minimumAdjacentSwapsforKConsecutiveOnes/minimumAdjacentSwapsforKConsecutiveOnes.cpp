// Source: https://leetcode.com/problems/minimum-adjacent-swaps-for-k-consecutive-ones/
// Author: Miao Zhang
// Date:   2021-05-29

class Solution {
public:
    int minMoves(vector<int>& nums, int k) {
        vector<int> p;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                p.push_back(i);
            }
        }
        int sums = 0;
        for (int i = 0; i < k; i++) {
            sums += abs(p[i] - p[k / 2]);
        }
        int res = sums;
        for (int i = 0; i + k < p.size(); i++) {
            int mid = i + k / 2;
            sums -= abs(p[mid] - p[i]);
            sums += abs(p[i + k] - p[mid + 1]);
            sums += k/ 2 * (p[mid + 1] - p[mid]);
            sums -= (k - 1 - k / 2) * (p[mid + 1] - p[mid]);
            res = min(res, sums);
        }
        int offset = 0;
        for (int i = 0; i < k; i++) {
            offset += abs(i - k / 2);
        }
        return res - offset;
    }
};
