// Source: https://leetcode.com/problems/find-k-th-smallest-pair-distance/
// Author: Miao Zhang
// Date:   2021-03-03

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0;
        int r = nums.back() - nums.front();
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (counter(nums, mid, k)) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }

    int counter(vector<int>& nums, int mid, int k) {
        int cnt = 0, left = 0;
        for (int right = 0; right < nums.size(); right++) {
            while (nums[right] - nums[left] > mid) {
                left++;
            }
            cnt += right - left;
        }
        return cnt >= k;
    }
};
