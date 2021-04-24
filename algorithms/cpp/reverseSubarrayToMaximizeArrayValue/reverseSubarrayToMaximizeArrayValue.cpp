// Source: https://leetcode.com/problems/reverse-subarray-to-maximize-array-value/
// Author: Miao Zhang
// Date:   2021-04-24

class Solution {
public:
    int maxValueAfterReverse(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int gain = 0;
        int hi = INT_MIN;
        int lo = INT_MAX;
        for (int i = 0; i < n - 1; ++i) {
            int n1 = nums[i];
            int n2 = nums[i + 1];
            sum += abs(n1 - n2);
            gain = max({gain,
                        abs(nums[0] - n2) - abs(n1 - n2),
                       abs(nums[n - 1] - n1) - abs(n1 - n2)});
            hi = max(hi, min(n1, n2));
            lo = min(lo, max(n1, n2));
        }
        return sum + max(gain, (hi - lo) * 2);
    }
};
