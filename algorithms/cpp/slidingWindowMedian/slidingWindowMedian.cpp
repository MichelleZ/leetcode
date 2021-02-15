// Source: https://leetcode.com/problems/sliding-window-median/
// Author: Miao Zhang
// Date:   2021-02-15

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res;
        if (k == 0) return res;
        vector<int> window(nums.begin(), nums.begin() + k - 1);
        std::sort(window.begin(), window.end());
        for (int i = k - 1; i < nums.size(); i++) {
            window.push_back(nums[i]);
            auto it = prev(window.end(), 1);
            auto const insertion_point = std::upper_bound(window.begin(), it, *it);
            std::rotate(insertion_point, it, it + 1);
            res.push_back(((double)window[k / 2] + (double)window[(k - 1) / 2]) / 2);
            window.erase(std::lower_bound(window.begin(), window.end(), nums[i - k + 1]));
        }
        return res;
    }
};
