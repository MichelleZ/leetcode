// Source: https://leetcode.com/problems/count-number-of-nice-subarrays/
// Author: Miao Zhang
// Date:   2021-04-19

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> odd;
        odd.push_back(-1);
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 1) {
                odd.push_back(i);
            }
        }
        odd.push_back(n);
        int m = odd.size();
        long long res = 0;
        for (int i = 1; i < m - k; i++) {
            res += (long)(odd[i] - odd[i - 1]) * (long)(odd[i + k] - odd[i + k - 1]);
        }
        return res;
    }
};
