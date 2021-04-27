// Source: https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/
// Author: Miao Zhang
// Date:   2021-04-27

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> s(nums);
        sort(s.begin(), s.end());
        int n = nums.size();
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = distance(begin(s), lower_bound(begin(s), end(s), nums[i]));
        }
        return res;
    }
};
