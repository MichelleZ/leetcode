// Source: https://leetcode.com/problems/valid-triangle-number/
// Author: Miao Zhang
// Date:   2021-02-24

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if (nums.size() < 3) return 0;
        std::sort(nums.rbegin(), nums.rend());
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n - 2; i++) {
            int l = i + 1;
            int r = n - 1;
            while (l < r) {
                if (nums[l] + nums[r] > nums[i]) {
                    res += (r - l);
                    l++;
                } else {
                    r--;
                }
            }
        }
        return res;
    }
};
