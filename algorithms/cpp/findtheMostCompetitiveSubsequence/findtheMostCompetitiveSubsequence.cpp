// Source: https://leetcode.com/problems/find-the-most-competitive-subsequence/
// Author: Miao Zhang
// Date:   2021-05-27

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res(k);
        int j = 0;
        for (int i = 0; i < n; i++) {
            while (j && res[j - 1] > nums[i] && j + n - i - 1 >= k) {
                j--;
            }
            if (j < k)
                res[j++] = nums[i];
        }
        return res;
    }
};
