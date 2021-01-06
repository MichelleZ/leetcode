// Source: https://leetcode.com/problems/4sum/
// Author: Miao Zhang
// Date:   2021-01-06

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int k = j + 1;
                int l = n - 1;
                while (k < l) {
                    if (nums[i] + nums[j] + nums[k] + nums[l] == target) {
                        vector<int> tmp;
                        tmp.push_back(nums[i]);
                        tmp.push_back(nums[j]);
                        tmp.push_back(nums[k]);
                        tmp.push_back(nums[l]);
                        res.push_back(tmp);
                        k++;
                        while (k < l && nums[k] == nums[k - 1]) k++;
                        l--;
                        while (k < l && nums[l] == nums[l + 1]) l--;
                    } else if (nums[i] + nums[j] + nums[k] + nums[l] < target) {
                        k++;
                    } else {
                        l--;
                    }
                }
            }
        }
        return res;
    }
};
